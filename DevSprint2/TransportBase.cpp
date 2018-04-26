#include "TransportBase.h"
#include "GlobalConstants.h"

TransportBase::TransportBase(float speed,ALLEGRO_COLOR color)
{
	trackspeed = speed;
	trackColor = color; //being resset to null
}



TransportBase::TransportBase()
{
}

TransportBase::~TransportBase()
{
}


void TransportBase::addItems(ItemBase &Items)
{
	ItemsOntrack.push_back(Items);
}

void TransportBase::removeItems()
{
	ItemsOntrack.erase(ItemsOntrack.begin());
}

//Set the connection for transportation between two machines.
void TransportBase::setConnection(MachineBase &start, MachineBase &end)
{
	startingNode(start);
	enddingNode(end);
	//Get the center points of the starting machine and the ending machine.
	float ScenterX = start.getPlacementX() + start.getWidth() / 2.0;
	float ScenterY = start.getPlacementY() + start.getHeight() / 2.0;

	float EcenterX = end.getPlacementX() + end.getWidth() / 2.0;
	float EcenterY = end.getPlacementY() + end.getHeight() / 2.0;

	layTrack(ScenterX, ScenterY, EcenterX, EcenterY);
}


void TransportBase::startingNode(MachineBase &start)
{
	startMachine = &start;
}

void TransportBase::enddingNode(MachineBase &end)
{
	endMachine = &end;
}



void TransportBase::Compute()
{
	if (startMachine->OutBuffer.n > 0)
	{
		//TODO: check somehow to make sure track is not full
		if ((ItemsOntrack.size() == 0) || 
			!(abs(ItemsOntrack.back().getCoordinateX() - start_x) < GC::itemImgDim /2 &&
			abs(ItemsOntrack.back().getCoordinateY() - start_y) < GC::itemImgDim /2))
		{
			startMachine->OutBuffer.n--;				// decrease amount of items in stack of the out buffer. 
			ItemBase temp;							// create a temp ItemBase Object.
			temp = startMachine->OutBuffer.i;		// Assign this temp to be a copy of the item of the out buffer.
			temp.setXY(start_x - GC::itemImgDim /2, start_y - GC::itemImgDim /2 );			// set the x and y of this object to the tracks startig x and y.
			ItemsOntrack.push_back(temp);			// push to the back of the Items on track vector.
		}
	}
	TransportItems(); // Do the moving of objects on the TrackVector.
}

void TransportBase::Draw()
{
	al_draw_line(start_x,start_y,end_x,end_y,al_map_rgb(60, 60, 60),3);

	if(!ItemsOntrack.empty())
	{
		
		for (int y = 0; y < this->ItemsOntrack.size(); y++)
		{
			this->ItemsOntrack.at(y).Draw();
		}
		
	}
}

//setup the stats of the track and set the tracks endpoints
void TransportBase::layTrack(float sx, float sy, float ex, float ey)
{
	start_x = sx;
	start_y = sy;
	end_x = ex;
	end_y = ey;

	trackDistance = sqrt(pow(abs(start_x - end_x), 2) + pow(abs(start_y - end_y), 2));
	trackLength = abs(start_x - end_x);
	trackHeight = abs(start_y - end_y);

	int TILESIZE = 64; //TODO Should be changed with global TILE SIZE

	trackSegments = round(trackDistance / TILESIZE);


}

void TransportBase::removeTrack()
{
}

void TransportBase::checkEndMachine()
{
	if (abs(ItemsOntrack.front().getCoordinateX() - end_x) < GC::itemImgDim /2 ||
		abs(ItemsOntrack.front().getCoordinateY() - end_y) < GC::itemImgDim /2)
	{
		for (int y = 0; y < endMachine->InputBuffer.size(); y++)
		{
			if (endMachine->InputBuffer.at(y).n < endMachine->InputBuffer.at(y).max) // check if inputbuffer is full before adding items
			{
				if (endMachine->InputBuffer.at(y).i.getName() == ItemsOntrack.front().getName())
				{
					ItemsOntrack.erase(ItemsOntrack.begin());
					endMachine->InputBuffer[y].n++;
					TrackStop = false;
					break;
				}
			}
			else
			{
				TrackStop = true;
				break;
			}
		}
	}
}

void TransportBase::MoveObject(int index)
{
	int CPS = 60; //TODO change this to global CPS
				  /*
				  track speed is the amount of seconds it takes to travel one segment..

				  (tracklength 300px  / 6 track segments)   /	(trackspeed  1  *  60ticks this second)


				  */
	int div1;
	float div2;
	if (trackSegments == 0)
	{
		div1 = 1;
	}
	else
	{
		div1 = trackSegments;
	}

	if ((trackspeed *(1.0f*CPS)) == 0)
	{
		div2 = 1;
	}
	else
	{
		div2 = (trackspeed *(1.0f*CPS));
	}

	float x = ItemsOntrack.at(index).getCoordinateX() + ((trackLength / trackSegments) / (trackspeed *(1.0f*CPS)));
	float y = ItemsOntrack.at(index).getCoordinateY() + ((trackHeight / trackSegments) / (trackspeed *(1.0f*CPS)));
	this->ItemsOntrack.at(index).setXY(x, y);
}

//transport items over the track.
void TransportBase::TransportItems()
{
	
	if (!ItemsOntrack.empty())
	{
		checkEndMachine();
		for (int n=0; n < ItemsOntrack.size(); n++)
		{
			if (TrackStop)
			{
				if (n > 0)
				{
					if (  (abs(ItemsOntrack.at(n - 1).getCoordinateY() - ItemsOntrack.at(n).getCoordinateY()) > GC::itemImgDim /2) ||
						  abs(ItemsOntrack.at(n - 1).getCoordinateX() - ItemsOntrack.at(n).getCoordinateX()) > GC::itemImgDim /2)
					{
						MoveObject(n);
					}
				}
			}
			else
			{
				MoveObject(n);
			}
		}
	}
}




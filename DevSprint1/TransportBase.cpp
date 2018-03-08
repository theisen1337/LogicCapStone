#include "TransportBase.h"


TransportBase::TransportBase(float speed,ALLEGRO_COLOR color)
{
	trackspeed = speed;
	trackColor = color;
}



TransportBase::TransportBase()
{
}

TransportBase::~TransportBase()
{
}


void TransportBase::addItems(ItemBase Items)
{
	ItemsOntrack.push_back(Items);
}

void TransportBase::removeItems()
{
	ItemsOntrack.pop_front();
}

void TransportBase::startingNode(MachineBase &start)
{
	startMachine = start;
}

void TransportBase::enddingNode(MachineBase &end)
{
	endMachine = end;
}

void TransportBase::Compute()
{
	if (startMachine.OutBuffer.n > 0)
	{
		//TODO: check someone to make sure track is not full
		startMachine.OutBuffer.n--;
		ItemBase temp = startMachine.OutBuffer.i;
		temp.setXY(start_x, start_y);
		addItems(temp);
	}
}

void TransportBase::Draw()
{
	al_draw_line(start_x,start_y,end_x,end_y,trackColor,5);

	if (!ItemsOntrack.empty())
	{
		
		for (int y = 0; y < ItemsOntrack.size(); y++)
		{
			ItemsOntrack[y].Draw();
		}
		
	}
}

void TransportBase::layTrack(float sx, float sy, float ex, float ey)
{
	start_x = sx;
	start_y = sy;
	end_x = ex;
	end_y = ey;

	trackDistance = sqrt(pow(abs(start_x - end_x), 2) + pow(abs(start_y - end_y), 2));
	trackLength = abs(start_x - end_x);
	trackHeight = abs(start_y - end_y);

	int TILESIZE = 64; //Should be changed with global TILE SIZE

	trackSegments = round(trackDistance / TILESIZE);


}

void TransportBase::removeTrack()
{
}

void TransportBase::TransportItems()
{
	if (!ItemsOntrack.empty())
	{
		if (ItemsOntrack.front().getCoordinateX() > end_x || ItemsOntrack.front().getCoordinateY() > end_y)
		{
			for (int y = 0; y < endMachine.InputBuffer.size(); y++)
			{
				if (endMachine.InputBuffer[y].i.getName() == ItemsOntrack.front().getName())
				{
					//TODO check if inputbuffer is full before adding items
					ItemsOntrack.pop_front();
					endMachine.InputBuffer[y].n++;
					break;
				}
			}
		}

		for (int n=0; n < ItemsOntrack.size(); n++)
		{
			int CPS = 60; //TODO change this to global CPS
			/*
			track speed is the amount of seconds it takes to travel one segment..
			
			     (tracklength 300px  / 6 track segments)   /	(trackspeed  1  *  60ticks this second)


			*/
			float x = ItemsOntrack[n].getCoordinateX() + ((trackLength / trackSegments) / (trackspeed *(1.0f*CPS)));
			float y = ItemsOntrack[n].getCoordinateY() + ((trackHeight / trackSegments) / (trackspeed *(1.0f*CPS)));
			ItemsOntrack[n].setXY(x,y);
		}

		
	}
}




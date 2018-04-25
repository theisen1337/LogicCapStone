#include "MachineBase.h"
#include "FileIO.h"

MachineBase::MachineBase()
{
	Busy = false;
}

MachineBase::~MachineBase() {}

//Recipe information

void MachineBase::setCraftRecipe(std::vector<Stack> recipe)
{
	CraftRecipe = recipe;
	if (!recipe.empty())
	{
		for (int i = 0; i < recipe.size(); i++)
		{
			recipe[i].max = recipe[i].n * 3;
			recipe[i].n = 0;
		}
	}
		
	InputBuffer = recipe;
}

void MachineBase::setCraftRecipe(std::vector<Stack> recipe,int multiplier)
{
	CraftRecipe = recipe;
	if (!recipe.empty())
	{
		for (int i = 0; i < recipe.size(); i++) 
		{
			recipe[i].max = recipe[i].n * multiplier;
			recipe[i].n = 0; //so input does not start with items
			
		}		
	}
	InputBuffer = recipe;
}

void MachineBase::setCraftRecipe(std::vector<Stack> recipe, int *multiplier)
{
	CraftRecipe = recipe;
	if (!recipe.empty())
	{
		for (int i = 0; i < recipe.size(); i++)
		{
			recipe[i].max = multiplier[i];
			recipe[i].n = 0;
		}
	}
	InputBuffer = recipe;
}

std::vector<Stack> MachineBase::getCraftRecipe()
{
	return CraftRecipe;
}

//Work for the machine

void MachineBase::setTotalWork(float totalWork)
{
	MachineBase::totalWork = totalWork;
	jobWork = totalWork;
}

float MachineBase::getTotalWork()
{
	return totalWork;
}

void MachineBase::setWorkPerSecond(float WorkPerSecond)
{
	MachineBase::WorkPerSecond = WorkPerSecond;
}

float MachineBase::getWorkPerSecond()
{
	return WorkPerSecond;
}

//

bool MachineBase::isWorking()
{
	return Busy;
}

void MachineBase::doWork()
{
	if (OutBuffer.n < OutBuffer.max)
	{
		int AmountofTicksPerSecond = 50; //TODO set to the number of tickets replace with CPS later, should be static
		jobWork -= (WorkPerSecond / (1.0f*AmountofTicksPerSecond));
		if (jobWork <= 0)
		{
			Busy = false;
			jobWork = totalWork;
			OutBuffer.n += 1*OutBufferMultiplier;
		}//TODO logic glitch were if NOT OutBuffer.n < OutBuffer.max and Busy equals true its not turned off. to not Busy.
	}
}

//Main Meat and potatos

void MachineBase::Compute()
{
	if (Busy)
	{
		doWork();
	}
	else
	{
		for (int n = 0; n < InputBuffer.size(); n++)
		{
			if (InputBuffer[n].n < CraftRecipe[n].n)
				return; //end method if there is not enough ingredents for recipe.
		}

		for (int n = 0; n < InputBuffer.size(); n++) //Remove the Items in the Input, and use them for the recipe.
		{
			InputBuffer[n].n -= CraftRecipe[n].n;
		}

		Busy = true;
		doWork(); //do one iteration of work for this tick.
	}
}

void MachineBase::Draw()
{
	if(Busy)
		al_draw_scaled_bitmap(MAS_ON_Image,0,0,48,48,
			placementX, placementY, Width, Height, 0);
	else
		al_draw_scaled_bitmap(MAS_OFF_Image, 0, 0, 48, 48,
			placementX, placementY, Width, Height, 0);
}

//Placement methods

void MachineBase::setPlacement(float x, float y)
{
	placementX = x;
	placementY = y;
}

void MachineBase::setName(std::string m_name)
{
	name = m_name;
}

std::string MachineBase::getName()
{
	return name;
}

float MachineBase::getPlacementX()
{
	return placementX;
}

float MachineBase::getPlacementY()
{
	return placementY;
}

float MachineBase::getHeight()
{
	return Height;
}

float MachineBase::getWidth()
{
	return Width;
}

void MachineBase::setTile(int x, int y)
{
	TileX = x;
	TileY = y;
}

int MachineBase::getTileX()
{
	return TileX;
}

int MachineBase::getTileY()
{
	return TileY;
}

void MachineBase::setInBuffer(std::vector<Stack> input)
{
	InputBuffer = input;
}

void MachineBase::setAnimateSheet_OFF(std::string path)
{
	FileIO file;
	MAS_OFF_Image = al_load_bitmap(file.openPicture(path).c_str());
	//MAS_OFF_Image =  &pic; //better idlea pass in string and do file load here.
}

void MachineBase::setAnimateSheet_ON(std::string path)
{
	FileIO file;
	MAS_ON_Image = al_load_bitmap(file.openPicture(path).c_str());
}

void MachineBase::setAnimateSheet_IDLE(std::string path)
{
	FileIO file;
	MAS_IDLE_Image = al_load_bitmap(file.openPicture(path).c_str());
	//MAS_IDLE_Image = &pic;
}

void MachineBase::setOutBuffer(Stack output, int multiplier)
{
	OutBuffer = output;
	OutBufferMultiplier = multiplier;
}

void MachineBase::leftClick()
{

	// Setup ImGui binding
	//ImGui_ImplA5_Init(display);

	// Setup style
	//ImGui::Button("test");
	/*al_show_native_message_box(al_get_current_display(),
		"Character Interaction",
		"Character left clicked on a coal ore",
		"Success",
		NULL, ALLEGRO_MESSAGEBOX_ERROR);*/

	std::string output = "";
	std::string msg = "";
	output += "########################################################################################\n";
	output += "InputBuffer:\n";
	for (int i = 0; i < InputBuffer.size(); i++)
	{
		output += "\tInputBuffer[";
		output += to_string(i);
		output += "].i = ";
		output += InputBuffer[i].i.getName();
		output += "\tInputBuffer[";
		output += to_string(i);
		output += "].n = ";
		output += to_string(InputBuffer[i].n);
		output += "\tInputBuffer[";
		output += to_string(i) + "";
		output += "].max = ";
		output += to_string(InputBuffer[i].max);
		output += "\n";
	}

		output += "CraftRecipe:\n";
	for (int i = 0; i < CraftRecipe.size(); i++)
	{
		output += "\tCraftRecipe[";
		output += to_string(i);
		output += "].i = ";
		output += CraftRecipe[i].i.getName();
		output += "\tCraftRecipe[";
		output += to_string(i);
		output += "].n = ";
		output += to_string(CraftRecipe[i].n);
		output += "\tCraftRecipe[";
		output += to_string(i);
		output += "].max = ";
		output += to_string(CraftRecipe[i].max);
		output += "\n";
	}

	output += "OutBuffer:\n";
	output += "\tOutBuffer.i = ";
	output += OutBuffer.i.getName();
	output += "\tCraftOutBuffer.n = ";
	output += to_string(OutBuffer.n);
	output += "\tCraftOutBuffer.max = ";
	output += to_string(OutBuffer.max);
	output += "\n";

	output += "Work:\n";
	output += "\ttotalWork = ";
	output += to_string(totalWork);
	output += "\tjobWork = ";
	output += to_string(jobWork);
	output += "\tworkPerSecond = ";
	output += to_string(WorkPerSecond);
	output += "\n";;
	output += "########################################################################################\n";

	std:cout << output;

		al_show_native_message_box(al_get_current_display(),
			"Machine",
			output.c_str(),
			"Success",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);

}

void MachineBase::rightClick()
{
}



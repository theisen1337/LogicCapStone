#include "MachineBase.h"
#include "FileIO.h"


MachineBase::MachineBase()
{
	Busy = false;
}




MachineBase::~MachineBase()
{
}

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
			PlacementX, placementY, Width, Height, 0);
	else
		al_draw_scaled_bitmap(MAS_OFF_Image, 0, 0, 48, 48,
			PlacementX, placementY, Width, Height, 0);
}

//Placement methods

void MachineBase::setPlacement(float x, float y)
{
	PlacementX = x;
	placementY = y;
}

float MachineBase::getPlacementX()
{
	return PlacementX;
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

	std::cout << "########################################################################################\n";
	std::cout << "InputBuffer:\n";
	for (int i = 0; i < InputBuffer.size(); i++)
		std::cout << "\tInputBuffer[" << i << "].i = " << InputBuffer[i].i.getName() 
				  << "\tInputBuffer[" << i << "].n = " << InputBuffer[i].n 
		          << "\tInputBuffer[" << i << "].max = " << InputBuffer[i].max << endl;

	std::cout << "CraftRecipe:\n";
	for (int i = 0; i < CraftRecipe.size(); i++)
		std::cout << "\tCraftRecipe[" << i << "].i = " << CraftRecipe[i].i.getName()
		<< "\tCraftRecipe[" << i << "].n = " << CraftRecipe[i].n
		<< "\tCraftRecipe[" << i << "].max = " << CraftRecipe[i].max << endl;

	std::cout << "OutBuffer:\n";
		std::cout << "\tOutBuffer.i = " << OutBuffer.i.getName()
		<< "\tCraftOutBuffer.n = " << OutBuffer.n
		<< "\tCraftOutBuffer.max = " << OutBuffer.max << endl;

	std::cout << "Work:\n";
		std::cout << "\ttotalWork = " << totalWork
		<< "\tjobWork = " << jobWork
		<< "\tworkPerSecond = " << WorkPerSecond << endl;
		std::cout << "########################################################################################\n";

		al_show_native_message_box(al_get_current_display(),
			"Machine",
			"",
			"Success",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);

}

void MachineBase::rightClick()
{
}



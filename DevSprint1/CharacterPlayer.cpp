#include "CharacterPlayer.h"
#include "FileIO.h"



CharacterPlayer::CharacterPlayer()
{
	FileIO file;
	//characterPIC = al_load_bitmap(file.openPicture("Character//Character.png").c_str());
}


CharacterPlayer::~CharacterPlayer()
{
}

void CharacterPlayer::InitializeClass()
{
	characterPIC = al_load_bitmap("Character//Character.png");
}
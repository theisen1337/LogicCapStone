#include "CharacterPlayer.h"
#include "FileIO.h"



CharacterPlayer::CharacterPlayer()
{
	FileIO file;
	characterPIC = al_load_bitmap("Character//Character.png");
}


CharacterPlayer::~CharacterPlayer()
{
}

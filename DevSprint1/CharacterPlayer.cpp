#include "CharacterPlayer.h"
#include "FileIO.h"



CharacterPlayer::CharacterPlayer()
{
	FileIO file;
	characterPIC = file.openPicture("Character//Character.png");
}


CharacterPlayer::~CharacterPlayer()
{
}

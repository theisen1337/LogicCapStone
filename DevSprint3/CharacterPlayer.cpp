#include "CharacterPlayer.h"
#include "FileIO.h"

// ###############
// # CONSTRUCTOR #
// ###############
CharacterPlayer::CharacterPlayer()
{
	FileIO file;
}

// #################
// # DECONSTRUCTOR #
// #################
CharacterPlayer::~CharacterPlayer() {}

// ########################
// # INITIALIZE CHARACTER #
// ######################## 
void CharacterPlayer::InitializeClass()
{
	charRef = "Character.png";

}
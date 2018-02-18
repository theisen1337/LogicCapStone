#pragma once


class CharacterMovement 
{
public:
	CharacterMovement(int xPosition, int yPosition);
	int moveCharacterLeft(int distance = 5);
	int moveCharacterRight(int distance = 5);
	int moveCharacterUp(int distance = 5);
	int moveCharacterDown(int distance = 5);
	int getCharacterXPosition();
	void setCharacterXPosition(int x);
	int getCharacterYPosition();
	void setCharacterYPosition(int y);

private:
	int characterYPosition = 0;
	int characterXPosition = 0;
};
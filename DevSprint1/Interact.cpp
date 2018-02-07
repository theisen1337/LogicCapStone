#include "Interact.h"

Interact::Interact() {}
Interact::~Interact() {}

// Constantly check for mouse_b & 1
// OR
// Character checks for mouse_b and will call either of the two functions below
void Interact::leftClick()
{
	// Check mouse position (x and y)
	// Check relative position to other objects within ____ of the cursor
	// Then call the function of the appropriate object
}

// Call if mouse_b & 2
void Interact::rightClick()
{
	// Check mouse position (x and y)
	// Check relative position to other objects within ____ of the cursor
	// Then call the function of the appropriate object
}

// This calls the appropriate interaction functions in whatever object got clicked
void Interact::callFunctions()
{
	//If X object was clicked,
	//	If left clicked,
	//		Call function
	//	If right clicked,
	//		Call function

	// If Y object ...
}
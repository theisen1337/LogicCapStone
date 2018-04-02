#include "Interact.h"

// #####################
// # OLD K-D TREE CODE #
// #####################
/*

const int MAX_DIM = 3;

struct kd_node_t
{
	double x[MAX_DIM];
	struct kd_node_t *left, *right;
};

inline double dist(struct kd_node_t *a, struct kd_node_t *b, int dim)
{
	double t, d = 0;
	while (dim--)
	{
		t = a->x[dim] - b->x[dim];
		d += t*t;
	}
	return d;
}

inline void swap(struct kd_node_t *x, struct kd_node_t *y)
{
	double tmp[MAX_DIM];
	memcpy(tmp, x->x, sizeof(tmp));
	memcpy(x->x, y->x, sizeof(tmp));
	memcpy(y->x, tmp, sizeof(tmp));
}

struct kd_node_t* find_median(struct kd_node_t *start, struct kd_node_t *end, int idx)
{
	if (end <= start) return NULL;
	if (end == start + 1) return start;

	struct kd_node_t *p, *store, *md = start + (end - start) / 2;
	double pivot;

	while (1)
	{
		pivot = md->x[idx];

		swap(md, end - 1);
		for (store = p = start; p < end; p++)
		{
			if (p->x[idx] < pivot)
			{
				if (p != store)
					swap(p, store);
				store++;
			}
		}
		swap(store, end - 1);

		// if the median has duplicate values
		if (store->x[idx] == md->x[idx])
			return md;

		if (store > md) end = store;
		else start = store;
	}
}

struct kd_node_t* make_tree(struct kd_node_t *t, int len, int i, int dim)
{
	struct kd_node_t *n;

	if (!len) return 0;

	if ((n = find_median(t, t + len, i)))
	{
		i = (i + 1) % dim;
		n->left = make_tree(t, n - t, i dim);
		n->right = make_tree(n + 1, t + len - (n + 1), i, dim);
	}
	return n;
}

// Global for Now, Will Change
int visited = 0;

void nearest(struct kd_node_t *root, struct kd_node_t *nd, int i, int dim, struct kd_node_t **best, double *best_dist)
{
	double d, dx, dx2;

	// If there is no root, then return
	if (!root) return;

	// Calculate Distance
	// root = root tree
	// nd = mouse position
	// dim = number of dimensions
	d = dist(root, nd, dim);

	dx = root->x[i] - nd->x[i];
	dx2 = dx * dx;

	visited++;

	// If found is not a set variable or if new distance is less than current best
	if (!*best || d < *best_dist)
	{
		// Set the new best distance
		*best_dist = d;
		// update the root
		*best = root;
	}

	// If there is no best distance, return
	if (!*best_dist) return;

	// Performs dimension shifts (horizontal, vertical, horizontal, etc.)
	if (++i >= dim) i = 0;

	// Recursively search left tree
	nearest(dx > 0 ? root->left : root->right, nd, i, dim, best, best_dist);

	// If dx2 is larger than the best_dist, then return (base case)
	if (dx2 >= *best_dist) return;

	// recursively search right tree
	nearest(dx > 0 ? root->right : root->left, nd, i, dim, best, best_dist);
}

// PLACE BELOW CODE IN INITIALIZATION

struct kd_node_t wp[] = { current X, Y positions }
struct kd_node_t testNode = { mouse positioning }
struct kd_node_t *root, *found;
double best_dist;

root = make_tree(wp, sizeof(wp) / sizeof(wp[1]), 0, 2);

visited = 0;
found = 0;

// Root = Origin of Tree
// TestNode = Where Mouse is Located
// 0 is single iteration
// 2 is the dimensions
// Found is where the nearest coordinate is
// best_dist is what the distance is
nearest(root, &testNode, 0, 2, &found, &best_dist);

cout << "Searching for " + testNode.x[0] + testNode.x[1] << endl;
cout << "Found " + found->x[0], found->x[1];
cout << "Distance " + sqrt(best_dist);
cout << "Visited " + visited + " nodes.";

*/

// ####################
// # Create our Event #
// ####################
ALLEGRO_EVENT event;

// ###############
// # Constructor #
// ###############
Interact::Interact() {}

// #################
// # Deconstructor #
// #################
Interact::~Interact() {}

// #########################
// # Interact with Objects #
// #########################
void Interact::interactions(int mouseX, int mouseY, int mouseB, ObjectManager &OM, float screenX, float screenY)
{
	// Stores Previously Calculated Distance
	int prevDistance = 0;
	// Stores Newly Calculated Distance
	int newDistance = 0;
	// Stores X Position of Object
	int objectX = 1000000;
	// Stores Y Position of Object
	int objectY = 1000000;
	// Stores Index in Array of Object
	int objectIndex = 0;

	// Initializes Distance (Very High as We Want the First Object Right Away)
	prevDistance = sqrt(pow((mouseX - objectX), 2) + pow((mouseY - objectY), 2));

	// LOOP FOR ITEM OBJECTS (CURRENTLY NONE)
	/*

	// Loops Through the Item Layer and Finds Closest Item to the Mouse Release
	for (int i = 0; i < OM.getIL().arrItems.size(); i++)
	{
		// Calculates New Distance Between Mouse and Object from Item Layer
		newDistance = sqrt(pow((mouseX - OM.getIL().arrItems[i].getCoordinateX()), 2) + pow((mouseY - OM.getIL().arrItems[i].getCoordinateY()), 2));

		// If the Newly Calculated Distance is Closer than the Previous ...
		if (newDistance < prevDistance)
		{
			// Set the New Distance to the Old Distance
			prevDistance = newDistance;
			// Store the X and Y Coordinate of the Object as well as the Index in the Array
			objectX = OM.getIL().arrItems[i].getCoordinateX();
			objectY = OM.getIL().arrItems[i].getCoordinateY();
			objectX += 8;
			objectY += 8;
			objectIndex = i;
		}
	}

	// If the smallest distance found from the for loop is less than 10 ...
	// (So if the closest object is within 10 "pixels" of the mouse)
	// DEPRECIATED AND NOT IN USE UNTIL ITEM INTERACTION NEEDED
	if (prevDistance < 10)
	{
		// If the Left Button was Pressed ...
		if (mouse == 1)
		{
			// Call the leftClick() Function of the Closest Object
			OM.getIL().arrItems[object_index].leftClick();
			return;
		}
		// If the Right Button was Pressed ...
		else if (mouse == 2)
		{
			// Call the rightClick() Function of the Closest Object
			OM.getIL().arrItems[object_index].rightClick();
			return;
		}
		// If Somehow No Button was Pressed (Possibly Error) ...
		else
		{
			return;
		}
	}
	*/

	// GRAB OBJECTS ON SCREEN (NOT WORKING)
	/*
	ObjectManager tempOM;

	for (int i = 0; i < OM.getML().arrMachines.size(); i++)
	{
		if (((OM.getML().arrMachines[i].getPlacementX() > screenX) &&
			(OM.getML().arrMachines[i].getPlacementX() < (screenX + 640))) &&
			((OM.getML().arrMachines[i].getPlacementY() > screenY) &&
			(OM.getML().arrMachines[i].getPlacementX() < (screenX + 480))))
		{
			tempOM.getML().arrMachines.resize(i + 1);
			tempOM.getML().arrMachines[i] = OM.getML().arrMachines[i];
		}
	}
	*/

	// Loops Through the Machine Layer and Finds Closest Machine to the Mouse Release
	for (int j = 0; j < OM.getML().arrMachines.size(); j++)
	{
		// Calculates New Distance Between Mouse and Object from Machine Layer
		newDistance = sqrt(pow((mouseX - OM.getML().arrMachines[j].getPlacementX()), 2) + pow((mouseY - OM.getML().arrMachines[j].getPlacementY()), 2));

		// If the Newly Calculated Distance is Closer than the Previous ...
		if (newDistance < prevDistance)
		{
			// Set the New Distance to the Old Distance
			prevDistance = newDistance;

			// Store the X and Y Coordinate of the Object as well as the Index in the Array
			objectX = OM.getML().arrMachines[j].getPlacementX();
			objectY = OM.getML().arrMachines[j].getPlacementY();

			// Add 32 to the X and Y to get the middle of the object and store index to object
			objectX += 32;
			objectY += 32;
			objectIndex = j;
		}
	}

	// Calculates the Newest Distance between Mouse and Center of Object
	newDistance = sqrt(pow((mouseX - objectX), 2) + pow((mouseY - objectY), 2));

	std::cout << "Distance to Nearest Object: " << newDistance << endl;

	// Sets the Boundaries of the Nearest Object
	maxX = objectX + 32;
	minX = objectX - 32;
	maxY = objectY + 32;
	minY = objectY - 32;

	// If the User Clicked Within the Object's Boundaries ...
	if ((mouseX < maxX && mouseX > minX) && (mouseY < maxY && mouseY > minY))
	{
		// If the Left Button was Pressed ...
		if (mouse == 1)
		{
			// Call the leftClick() Function of the Closest Object
			OM.getML().arrMachines[objectIndex].leftClick();
			return;
		}
		// If the Right Button was Pressed ...
		else if (mouse == 2)
		{
			// Call the rightClick() Function of the Closest Object
			OM.getML().arrMachines[objectIndex].rightClick();
			return;
		}
		// If Somehow No Button was Pressed (Possibly Error or middle mouse click) ...
		else
		{
			return;
		}
	}

	// LOOP THROUGH ORE OBJECTS (CURRENTLY NONE) (ALSO DEPRECIATED)
	/*
	for (int k = 0; k < oreLayer.arrOres.size(); k++)
	{
		new_distance = sqrt(pow((mouse_x - oreLayer.arrOres[k].getXCoordinate()), 2) + pow((mouse_y - oreLayer.arrOres[k].getYCoordinate()), 2));

		if (new_distance < prev_distance)
		{
			prev_distance = new_distance;
			object_x = oreLayer.arrOres[k].getXCoordinate();
			object_y = oreLayer.arrOres[k].getYCoordinate();
			object_index = k;
		}
	}
	
	if (prev_distance < 10)
	{
		if (mouse == 1)
		{
			oreLayer.arrOres[object_index].leftClick();
			return;
		}
		else if (mouse == 2)
		{
			oreLayer.arrOres[object_index].rightClick();
			return;
		}
		else
		{
			return;
		}
	}*/
}

// ####################################
// # Mouse and Keyboard Functionality #
// ####################################
bool Interact::beginInteractions(World &Map, MainDraw &Art, ALLEGRO_DISPLAY * display, ALLEGRO_FONT * font, ALLEGRO_EVENT_QUEUE  *queue, ObjectManager &OM, float screenX, float screenY)
{
	al_wait_for_event(queue, &event);

	// Checks to See if Window Closed
	if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
	{
		return false;
	}

	switch (event.type)
	{
	case ALLEGRO_EVENT_KEY_DOWN:
		switch (event.keyboard.keycode)
		{
		case ALLEGRO_KEY_UP:
			movement.vy -= movement.getSpeed();
			break;
		case ALLEGRO_KEY_DOWN:
			movement.vy += movement.getSpeed();
			break;
		case ALLEGRO_KEY_LEFT:
			movement.vx -= movement.getSpeed();
			break;
		case ALLEGRO_KEY_RIGHT:
			movement.vx += movement.getSpeed();
			break;
		case ALLEGRO_KEY_R:
			Map.initialGeneration();
		case ALLEGRO_KEY_ESCAPE:
			return false;
		}
		break;
	case ALLEGRO_EVENT_KEY_UP:
		switch (event.keyboard.keycode)
		{
		case ALLEGRO_KEY_UP:
			movement.vy += movement.getSpeed();
			break;
		case ALLEGRO_KEY_DOWN:
			movement.vy -= movement.getSpeed();
			break;
		case ALLEGRO_KEY_LEFT:
			movement.vx += movement.getSpeed();
			break;
		case ALLEGRO_KEY_RIGHT:
			movement.vx -= movement.getSpeed();
			break;
		case ALLEGRO_KEY_P:
			al_show_native_message_box(al_get_current_display(),
				"",
				"Paused",
				"",
				NULL, ALLEGRO_MESSAGEBOX_ERROR);
			break;
		}
		break;
	case ALLEGRO_EVENT_TIMER:
		movement.moveCharacterX();//DF
		if (movement.getCharacterXPosition() > mapXBoundary)
		{
			movement.setCharacterXPosition(mapXBoundary);
		}
		else if (movement.getCharacterXPosition() < 0)
		{
			movement.setCharacterXPosition(0);
		}
		movement.moveCharacterY();
		if (movement.getCharacterYPosition() > mapYBoundary)
		{
			movement.setCharacterYPosition(mapYBoundary);
		}
		else if (movement.getCharacterYPosition() < 0)
		{
			movement.setCharacterYPosition(0);
		}
		break;
		redraw = true;
	}

	// Checks for Mouse Button Press
	if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) 
	{
		startScreenX = screenX;
		startScreenY = screenY;

		al_get_mouse_state(&mousepos);
		mouse = event.mouse.button;
		float mouseposX = (float)mousepos.x;
		float mouseposY = (float)mousepos.y;

		startX = mouseposX + abs(startScreenX);
		startY = mouseposY + abs(startScreenY);

		startX *= 2; startY *= 2;

		std::cout << "Start Mouse: (" << mouseposX << ", " << mouseposY << ")" << endl;
		std::cout << "Start Screen: (" << abs(startScreenX) << ", " << abs(startScreenY) << ")" << endl;
		std::cout << "Initial Coordinates: (" << startX << ", " << startY << ")" << endl << endl;
	}

	// Checks for Mouse Button Release
	if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) 
	{
		endScreenX = screenX;
		endScreenY = screenY;

		al_get_mouse_state(&mousepos);
		float mouseposX = (float)mousepos.x;
		float mouseposY = (float)mousepos.y;

		endX = mouseposX + abs(endScreenX);
		endY = mouseposY + abs(endScreenY);

		endX *= 2; endY *= 2;

		std::cout << "End Mouse: (" << mouseposX << ", " << mouseposY << ")" << endl;
		std::cout << "End Screen: (" << abs(endScreenX) << ", " << abs(endScreenY) << ")" << endl;
		std::cout << "End Coordinates: (" << endX << ", " << endY << ")" << endl << endl;

		distance = sqrt(pow((endScreenX - startScreenX), 2) + pow((endScreenY - startScreenY), 2));

		if (distance < 2)
		{
			interactions(endX, endY, mouse, OM, endScreenX, endScreenY);
		}

		mouse = 0;
	}

	// Actions for Mouse Movement
	if (event.type == ALLEGRO_EVENT_MOUSE_AXES) {
		
		// If it was a Left Click, Scroll Across the Map
		if (mouse == 1) {
			float x = event.mouse.dx / zoom;
			float y = event.mouse.dy / zoom;
			scrollX -= x * cos(rotate) + y * sin(rotate);
			scrollY -= y * cos(rotate) - x * sin(rotate);
		}
		
		// If it was a Right Click, Zoom/Rotate the Map [CURRENTLY NOT AVAILABLE]
		if (mouse == 2) 
		{
			//rotate += event.mouse.dx * 0.01;
			//zoom += event.mouse.dy * 0.01 * zoom;
		}
		zoom += event.mouse.dz * 0.1 * zoom;
		if (zoom < 0.1) zoom = 0.1;
		if (zoom > 10) zoom = 10;
	}

	// Checks Timer to Redraw
	if (event.type == ALLEGRO_EVENT_TIMER)
		redraw = true;

	// Redraws when Window Changes Size
	if (event.type == ALLEGRO_EVENT_DISPLAY_RESIZE) 
	{
		al_acknowledge_resize(display);
		redraw = true;
	}

	return true;
}
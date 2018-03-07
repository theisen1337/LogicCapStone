#pragma once

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>

#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro_font.h"

#include "World.h"
#include "Interact.h"
#include "FileIO.h"
#include "MainDraw.h"
#include "ObjectManager.h"
#include "MainDraw.h"
#include "MainCompute.h"
#include "MachineLayer.h"
#include "TransportLayer.h"
#include "CharacterPlayer.h"
#include "transportTemplate.h"
#include "GlobalStatics.h"

using namespace std;

#pragma once
class StateManager
{
	public:
		ObjectManager ObjMang;
		GlobalStatics GlobStat;
		Interact Interactions;
		World Map;
		Interact interactions;
		MainDraw mainDraw;
		MainCompute mainCompute;
		CharacterPlayer player;

		// Window Used for Display
		ALLEGRO_DISPLAY *display;
		// Tilemap Test Image
		ALLEGRO_BITMAP *BlahtestImage;
		// Custom Font
		ALLEGRO_FONT *font;

		ALLEGRO_EVENT_QUEUE *queue;

		ALLEGRO_TRANSFORM transform;
		float w, h;

		ALLEGRO_TIMER *timer;

		void Transformations();
		void run();
		void Initialization();
		void Computing();
		void Drawing();
		void Interacting();
		void Exiting();

		bool GAMERUN = true;

		void MainLoop(); //World &Map, Artist &Art, ALLEGRO_DISPLAY * display, ALLEGRO_FONT * font
};


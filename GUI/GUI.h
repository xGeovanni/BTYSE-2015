#pragma once

#include "SDL.h"
#include "SDL_ttf.h"

#include <iostream>
#include <math.h>
#include <vector>
#include <string>

class GUI{
    int WIDTH;
    int HEIGHT;

    bool running;

	std::vector<std::string> options;
	std::vector<SDL_Surface*> renderedOptions;

    SDL_Rect selectorRect;
	SDL_Surface* selector;

    int yOffset;

	int selected;

    int fillColour;
	int flag;

    SDL_Surface *screen;
	SDL_Event e;

	SDL_Rect drawRect;

	TTF_Font *font;
	SDL_Colour fontColour;

	bool escapable;

	void update();
	void draw();
	void input();

public:
	GUI(std::vector<std::string>& _options, int fontSize = 48, bool _escapable = false);
	~GUI();
	int run();
};

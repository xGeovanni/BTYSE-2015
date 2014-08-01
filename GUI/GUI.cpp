#include "GUI.h"

GUI::GUI(std::vector<std::string>& _options, int fontSize, bool _escapable){
    options = _options;
    escapable = _escapable;

	fillColour = 0x00;

    fontColour.r = 0;
    fontColour.g = 0xCC;
    fontColour.b = 0;

    font = TTF_OpenFont("font.ttf", 48);

	selected = 0;
	selector = TTF_RenderText_Solid(font, ">", fontColour);
	selectorRect.x = 0;
	selectorRect.y = 0;

	WIDTH = 800;
	HEIGHT = 480;

	drawRect.x = WIDTH * .1;
	yOffset = 0;

	screen = SDL_SetVideoMode(WIDTH, HEIGHT, 8, 0 /*SDL_FULLSCREEN*/);

	for (int i=0; i < options.size(); i++){
	    renderedOptions.push_back(TTF_RenderText_Solid(font, options[i].c_str(), fontColour));
	}

	SDL_ShowCursor(0);
}

GUI::~GUI(){
    TTF_CloseFont(font);
}

int GUI::run(){
    running = true;

    while(running){
        update();
        draw();
        input();
    }

    return selected;
}

void GUI::update(){
}

void GUI::draw(){
    SDL_FillRect(screen, NULL, fillColour);

    int totalY = 0;

    for (int i=0; i < options.size(); i++){
        totalY += + renderedOptions[i]->h;
	}

	int height = std::max(totalY, HEIGHT);

    for (int i=0; i < options.size(); i++){
        drawRect.y = yOffset + (height + renderedOptions[i]->h) * ((float) i / (options.size()));
        if (i == selected){
            selectorRect.y = drawRect.y;

            if (selectorRect.y < 0){
                yOffset -= selectorRect.y;
                drawRect.y = yOffset + (height + renderedOptions[i]->h) * ((float) i / (options.size()));
                selectorRect.y = drawRect.y;
            }
            else if(selectorRect.y > HEIGHT){
                yOffset += (HEIGHT - (selectorRect.y + renderedOptions[i]->h));
                drawRect.y = yOffset + (height + renderedOptions[i]->h) * ((float) i / (options.size()));
                selectorRect.y = drawRect.y;
            }
        }
	    SDL_BlitSurface(renderedOptions[i], NULL, screen, &drawRect);
	}

	SDL_BlitSurface(selector, NULL, screen, &selectorRect);

    SDL_Flip(screen);
}

void GUI::input(){
    while(SDL_PollEvent(&e)){
        if (e.type == SDL_QUIT){
            running = false;
            selected = -1;
        }

        if (e.type == SDL_KEYDOWN){
            switch (e.key.keysym.sym){
                case (SDLK_BACKQUOTE):
                    running = false;
                    selected = -1;
                    break;
                case (SDLK_ESCAPE):
                    if (escapable){
                        running = false;
                        selected = -1;
                    }
                    break;
                case (SDLK_RETURN):
                    running = false;
                    break;
                case (SDLK_UP):
                    if (selected > 0){
                        selected--;
                    }
                    break;
                case (SDLK_DOWN):
                    if (selected < (options.size()-1)){
                        selected++;
                    }
                    break;
                default:
                    break;
            }
        }
    }
}

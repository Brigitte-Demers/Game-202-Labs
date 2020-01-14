/*
Name: Brigitte Demers.
Course: Game 202.
Prof: Majid Moghadam.
Title of Program: Game Programming.
Date: January 13th, 2020.
*/


//
#include "SDL.h"
#include <cstdlib>

//
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

//
SDL_Renderer *renderer;

/*
*BRIGITTE'S CHANGES* New global variable added.
*/
SDL_Event event;

// Mouse coordinates;
int mouse_x, mouse_y;

//
bool running = true;

//
SDL_Rect PlayerPaddle;
SDL_Rect AIPaddle;
SDL_Rect Ball;
/*
*BRIGITTE'S CHANGES* Added line object. 
*/
SDL_Rect Middle;

/*
Purpose of the LoadGamer function:
*/
void LoadGame()
{
	//
	SDL_Window *window;

	//
	window = SDL_CreateWindow("Basic SDL Sprites",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		WINDOW_WIDTH, WINDOW_HEIGHT,
		SDL_WINDOW_SHOWN);
	if (!window) {
		return;
	}

	//
	renderer = SDL_CreateRenderer(window, -1, 0);
	if (!renderer) {
		return;
	}

	//
	PlayerPaddle.x = 20;
	PlayerPaddle.y = 250;
	PlayerPaddle.h = 100;
	PlayerPaddle.w = 20;

	//
	AIPaddle.x = 760;
	AIPaddle.y = 250;
	AIPaddle.h = 100;
	AIPaddle.w = 20;

	//
	Ball.x = 370;
	Ball.y = 290;
	Ball.w = 20;
	Ball.h = 20;

	/* 
	*BRIGITTE"S CHANGES* Added the placement of the line.
	*/
	Middle.x = 395;
	Middle.y = 5;
	Middle.w = 10;
	Middle.h = 590;
}

/*
Purpose of the Input function:
*/
// Get user input.
void Input()
{
	// Queing events.
	while (SDL_PollEvent(&event))
	{
		// Track mouse movement.
		if (event.type == SDL_MOUSEMOTION)
			SDL_GetMouseState(&mouse_x, &mouse_y);

		// Clicking 'x' or pressing 'F4'.
		if (event.type == SDL_QUIT)
			running = false;

		// Pressing a key.
		if (event.type == SDL_KEYDOWN)
			switch (event.key.keysym.sym)
			{
				// Pressing 'ESC' exits from the game.
			case SDLK_ESCAPE:
				running = false;
				break;
			}
	}
}


/*
Purpose of Update function:
*/
void Update()
{
	PlayerPaddle.y = mouse_y;
	Ball.x += 1;
	Ball.y += 1;
	SDL_Delay(10);
}

/*
Purpose of the DrawScreen function;
*/
void DrawScreen()
{
	//
	SDL_RenderClear(renderer);

	//
	SDL_Rect background = { 0, 0, 800, 600 };
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderFillRect(renderer, &background);

	//
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(renderer, &PlayerPaddle);
	SDL_RenderFillRect(renderer, &AIPaddle);

	//
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(renderer, &Ball);

	/*
	*BRIGITTE'S CHANGES* Drawing the line in the middle of the screen.
	*/
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(renderer, &Middle);


	//
	SDL_RenderPresent(renderer);
}


/*
Purpose of the Quit function:
*/
void Quit()
{
	//
	SDL_Quit();
}

/*
Purpose of Main function:
*/
int main(int argc, char *argv[])
{
	//
	LoadGame();

	//
	while (running == true)
	{
		Input();         //
		Update();        //  
		DrawScreen();    //
	}

	//
	Quit();

	return 0;
}
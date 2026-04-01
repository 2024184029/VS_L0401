#include <iostream>
#include "SDL.h"
#pragma comment(lib, "SDL2")
#pragma comment(lib, "SDL2main")

using namespace std;

int SDL_main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING);

	// 윈도우, 렌더러 만들기
	SDL_Window* MyWindow = SDL_CreateWindow("Renderer", 100, 100, 1024, 768, SDL_WINDOW_SHOWN);
	SDL_Renderer* MyRenderer = SDL_CreateRenderer(MyWindow, -1, 0);

	int X = 100;
	int Y = 100;
	bool bIsRunning = true;

	while (bIsRunning)
	{
		// Input
		SDL_Event MyEvent;
		while (SDL_PollEvent(&MyEvent))
		{
			// Tick
			if (MyEvent.type == SDL_KEYDOWN)
			{
				if (MyEvent.key.keysym.sym == SDLK_w)
				{
					Y -= 10;
				}
				if (MyEvent.key.keysym.sym == SDLK_s)
				{
					Y += 10;
				}
				if (MyEvent.key.keysym.sym == SDLK_a)
				{
					X -= 10;
				}
				if (MyEvent.key.keysym.sym == SDLK_d)
				{
					X += 10;
				}
				if (MyEvent.key.keysym.sym == SDLK_ESCAPE)
				{
					bIsRunning = false;
				}
			}
		}

		// 배경
		SDL_SetRenderDrawColor(MyRenderer, 255, 255, 255, 255);
		SDL_RenderClear(MyRenderer);

		// 사각형
		SDL_SetRenderDrawColor(MyRenderer, 255, 0, 0, 255);
		SDL_Rect MyRect = { X, Y, 30, 30 };
		SDL_RenderDrawRect(MyRenderer, &MyRect);

		// 그리기
		SDL_RenderPresent(MyRenderer);
	}

	// 삭제하기
	SDL_DestroyRenderer(MyRenderer);
	SDL_DestroyWindow(MyWindow);
	SDL_Quit();

	return 0;
}

//
//  game_end.c
//  Game
//
//  Created by Leo Smith on 21/12/2016.
//  Copyright © 2016 Leo Smith. All rights reserved.
//

#include "game_end.h"

int win(int player, struct _game_data *gd)
{
	gd->end_lgc.pWin = player;
	while(!processWin(gd)){
		renderWin(gd);
		SDL_RenderPresent(gd->renderer);
		SDL_RenderClear(gd->renderer);
		SDL_Delay(10);
	}
	return 0;
}

int processWin(struct _game_data * game)  // process event is for key press and close button.
{
	SDL_Event event;
	int done = 0;
	
	while(SDL_PollEvent(&event))
	{
		switch(event.type)
		{
			case SDL_WINDOWEVENT_CLOSE:
			{
				if(game->window)
				{
					SDL_DestroyWindow(game->window);
					game->window = NULL;
					done = 1;
				}
			}
				break;
			case SDL_KEYDOWN:
			{
				switch(event.key.keysym.sym)
				{
					case SDLK_ESCAPE:
						done = 1;
						break;
					case SDLK_q:
						done = 1;
						break;
						
					case SDLK_SPACE:
						done = 1;
						break;
						
				}
			}
				break;
			case SDL_QUIT:
				//quit out of the game
				done = 1;
				break;
		}
		
		return done;
	}
	
	return done;
}

int renderWin(struct _game_data *gd)
{
	int alternate;
	
	alternate = 0;
	SDL_SetRenderDrawColor(gd->renderer, 100, 100, 100, 100);
	for(int x = 0; x < 1080; x+=100){
		for(int y = 0; y < HEIGTH; y+= 100){
			SDL_Rect wall = {x, y, 100, 100};
			if(alternate % 2){
				SDL_RenderCopy(gd->renderer, gd->menu_texture[0].texture, NULL, &wall);
			} else {
				SDL_RenderCopy(gd->renderer, gd->menu_texture[1].texture, NULL, &wall);
			}
			alternate++;
		}
	}
	SDL_Rect win = {100, 100, 600, 150};
	
	if(gd->end_lgc.pWin == 1)
		SDL_RenderCopy(gd->renderer, gd->p1Win.texture, NULL, &win);
	else
		SDL_RenderCopy(gd->renderer, gd->p2Win.texture, NULL, &win);

	
	return 0;
}

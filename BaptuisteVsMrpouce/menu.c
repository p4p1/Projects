//
//  renderProcess.c
//  Game
//
//  Created by Leo Smith on 29/11/2016.
//  Copyright © 2016 Leo Smith. All rights reserved.
//

#include "game_menu.h"

int processMenu(struct _game_data * game)  // process event is for key press and close button.
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
						game->menu_lgc.pressed_space = 1;
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

int renderMenu(struct _game_data * gd)
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
	
	SDL_Rect tit = {100, 50, 1000, 400};
	SDL_RenderCopy(gd->renderer, gd->title.texture, NULL, &tit);
	
	if(gd->menu_lgc.pressed_space != 1){
		SDL_Rect slct = {10, 270, 130, 130};
		SDL_RenderCopy(gd->renderer, gd->baptuiste.texture, NULL, &slct);
		SDL_Rect pg_text = {150, 300, 400, 100};
		SDL_RenderCopy(gd->renderer, gd->playGame.texture, NULL, &pg_text);
	} else {
		SDL_Rect slct = {10, 270, 200, 130};
		SDL_RenderCopy(gd->renderer, gd->baptuiste.texture, NULL, &slct);
		SDL_Rect pg_text = {220, 300, 400, 100};
		SDL_RenderCopy(gd->renderer, gd->playGame.texture, NULL, &pg_text);
		gd->in_game = 1;
		SDL_Delay(500);
	}
	
	SDL_RenderPresent(gd->renderer);
	if(gd->menu_lgc.pressed_space == 1){
		SDL_RenderClear(gd->renderer);
		gd->in_game = 1;
		SDL_Delay(2000);
	}
	return 0;
}

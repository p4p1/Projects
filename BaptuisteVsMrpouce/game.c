//
//  game.c
//  Game
//
//  Created by Leo Smith on 05/12/2016.
//  Copyright © 2016 Leo Smith. All rights reserved.
//

#include "game_main.h"

int game_logic(struct _game_data * gd)
{
	int num;
	
	num = 0;
	while(!(process_controls(gd)) && !(gd->game_lgc.player_dead)){
		render_game(gd, num);
		check_attack(gd);
		gravity(gd);
		if(gd->baptouiste.life <= 0 || gd->pouce.life <= 0)
			gd->game_lgc.player_dead++;
		gd->game_lgc.p1_attack = gd->game_lgc.p2_attack = 0;
		num++;
		
		SDL_Delay(25);
	}
	if(gd->baptouiste.life <= 0) {
		return 1;
	} else if(gd->pouce.life <= 0) {
		return 2;
	}
	
	return 0;
}

int process_controls(struct _game_data * gd)
{
	SDL_Event event;
	int done = 0;
	gd->game_lgc.k_pressed = 0;
	
	while(SDL_PollEvent(&event))
	{
		switch(event.type)
		{
			case SDL_WINDOWEVENT_CLOSE:
			{
				if(gd->window)
				{
					SDL_DestroyWindow(gd->window);
					gd->window = NULL;
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
					//player 1 controls
					case SDLK_a:	//left
						gd->game_lgc.k_pressed = 1;
						gd->pouce.x -= 10;
						gd->game_lgc.p1_left = 1;
						gd->game_lgc.p1_right = 0;
						break;
					case SDLK_s:	//right
						gd->game_lgc.k_pressed = 1;
						gd->pouce.x += 10;
						gd->game_lgc.p1_left = 0;
						gd->game_lgc.p1_right = 1;
						break;
					case SDLK_d:	//jump
						if(gd->pouce.y >= (720 - gd->pouce.h))
							gd->pouce.y -= 350;
						break;
					case SDLK_e:	//attack
						if(!gd->game_lgc.p1_attack){
							gd->game_lgc.p1_attack = 1;
							if(gd->game_lgc.p1_left)
								gd->pouce.x -= 100;
							else
								gd->pouce.x += 100;
						}
						break;
					//end p1
					//player 2 controls
					case SDLK_l:
						gd->game_lgc.k_pressed = 1;
						gd->baptouiste.x -= 20;
						gd->game_lgc.p2_left = 1;
						gd->game_lgc.p2_right = 0;
						break;
					case SDLK_k:	//right
						gd->game_lgc.k_pressed = 1;
						gd->baptouiste.x += 20;
						gd->game_lgc.p2_left = 0;
						gd->game_lgc.p2_right = 1;
						break;
					case SDLK_j:	//jump
						if(gd->baptouiste.y == (720 - gd->baptouiste.h))
							gd->baptouiste.y -= 100;
						break;
					case SDLK_u:	//attack
						if(!gd->game_lgc.p2_attack){
							gd->game_lgc.p2_attack = 1;
							if(gd->game_lgc.p2_left)
								gd->baptouiste.x -= 100;
							else
								gd->baptouiste.x += 100;
						}
						break;
					//endp2
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

int render_game(struct _game_data * gd, int animation)
{
	render_map(gd, animation);
	render_player(gd, animation);
	render_life(gd);
	
	SDL_RenderPresent(gd->renderer);
	SDL_RenderClear(gd->renderer);
	
	SDL_Delay(5);
	return 0;
}

int render_player(struct _game_data *gd, int animation)
{
	SDL_Rect p1 = {gd->pouce.x, gd->pouce.y, gd->pouce.w, gd->pouce.h};
	SDL_Rect p2 = {gd->baptouiste.x, gd->baptouiste.y, gd->baptouiste.w, gd->baptouiste.h};
	
	// Render player 1
	if(gd->game_lgc.k_pressed){

		if(!(animation % 10000)){
			if(gd->game_lgc.p1_frame)
				gd->game_lgc.p1_frame = 0;
			else
				gd->game_lgc.p1_frame = 1;
		}
		SDL_RenderCopy(gd->renderer, gd->pouce.texture[gd->game_lgc.p1_frame], NULL,
					&p1);
	} else {
		if(gd->game_lgc.p1_right)
			SDL_RenderCopy(gd->renderer, gd->pouce.texture[0], NULL, &p1);
		else
			SDL_RenderCopy(gd->renderer, gd->pouce.texture[1], NULL, &p1);
	}
	//end p1
	//Render player2
	if(gd->game_lgc.k_pressed){
		
		//if(!(animation % 1000)){
		//	if(gd->game_lgc.p1_frame)
		//		gd->game_lgc.p1_frame = 0;
		//	else
		//		gd->game_lgc.p1_frame = 1;
		//}
		SDL_RenderCopy(gd->renderer, gd->baptouiste.texture, NULL,
			       &p2);
	} else {
		if(gd->game_lgc.p1_right)
			SDL_RenderCopy(gd->renderer, gd->baptouiste.texture, NULL, &p2);
		else
			SDL_RenderCopy(gd->renderer, gd->baptouiste.texture,    NULL, &p2);
	}
	//end p2
	return 0;
}

int check_attack(struct _game_data *gd)
{
	int p1rs = gd->pouce.h+gd->pouce.x, p2rs = gd->baptouiste.h+gd->baptouiste.x;
	int p1ls = gd->pouce.h-gd->pouce.x, p2ls = gd->baptouiste.h-gd->baptouiste.x;
	//int p1ts = gd->pouce.w-gd->pouce.h, p2ts = gd->baptouiste.w-gd->baptouiste.h;
	
	if(p1rs >= p2rs && p1ls >= p2ls) {
		if(gd->game_lgc.p2_attack)
			gd->pouce.life -= 5;
		if(gd->game_lgc.p1_attack)
			gd->baptouiste.life -= 8;
		printf("%d/100 : %d/100\n", gd->pouce.life, gd->baptouiste.life);
	}
	if(gd->game_lgc.p2_attack) {
		//reset his position after attack
		if(gd->game_lgc.p2_left)
			gd->baptouiste.x += 100;
		else
			gd->baptouiste.x -= 100;
	}
	if(gd->game_lgc.p1_attack) {
		if(gd->game_lgc.p1_left)
			gd->pouce.x += 100;
		else
			gd->pouce.x -= 100;
	}
	
	
	return 0;
}

int render_life(struct _game_data *gd)
{
	SDL_SetRenderDrawColor(gd->renderer, 250, 0, 0, 0);
	for(int i = 0; i < gd->pouce.life; i++){
		SDL_Rect lifep1 = {i, 0, 10, 10};
		SDL_RenderDrawRect(gd->renderer, &lifep1);
	}
	for(int i = 0; i < gd->baptouiste.life; i++){
		SDL_Rect lifep2 = {WIDTH-i, 0, 10, 10};
		SDL_RenderDrawRect(gd->renderer, &lifep2);
	}
	
	return 0;
}

int render_map(struct _game_data *gd, int animation)
{
	
	SDL_Rect wallpaper = {0, 0, WIDTH, HEIGTH};
	SDL_RenderCopy(gd->renderer, gd->wallpaper.texture, NULL, &wallpaper);
	for(int i = 0; i < HEIGTH; i+=50) {
		SDL_Rect tile = {0, i, 50, 50};
		SDL_Rect tile2 = {1030, i, 50, 50};
		if(!(animation % 1000)){
			if(gd->game_lgc.foot_selected)
				gd->game_lgc.foot_selected = 0;
			else
				gd->game_lgc.foot_selected = 1;
		}
		SDL_RenderCopy(gd->renderer,
			gd->side_wall_texture[gd->game_lgc.foot_selected][0].texture, NULL, &tile);
		SDL_RenderCopy(gd->renderer,
			       gd->side_wall_texture[gd->game_lgc.foot_selected][1].texture, NULL, &tile2);
	}
	

	return 0;
}

void gravity(struct _game_data *gd)
{
	if(gd->pouce.y < 720 - gd->pouce.h) {
		gd->pouce.y+=25 ;
	}
	if(gd->baptouiste.y < 720 - gd->baptouiste.h) {
		gd->baptouiste.y++;
	}
}

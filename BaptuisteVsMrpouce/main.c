//
//  main.c
//  Game
//
//  Created by Leo Smith on 29/11/2016.
//  Copyright © 2016 Leo Smith. All rights reserved.
//

#include "main.h"
#include "game_menu.h"
#include "game_main.h"
#include "game_end.h"

int main(int argc, const char * argv[]) {
	
	struct _game_data gd;
	int winer;
	initFunc(&gd);
	loadSoundTextures(&gd);
	
	//Menu Loop
	Mix_PlayMusic(gd.music.menu_music, -1);
	while(!(processMenu(&gd)) && !(gd.in_game)){
		renderMenu(&gd);
		SDL_Delay(10);
	}
	Mix_FreeMusic(gd.music.menu_music);
	if(gd.in_game){
		winer = game_logic(&gd);
		win(winer, &gd);
	}
	
	quit(&gd);
	return 0;
}

int initFunc(struct _game_data * gd)
{
	TTF_Init();
	SDL_Init(SDL_INIT_VIDEO| SDL_INIT_AUDIO);              // Initialize SDL2
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
	
	gd->window = SDL_CreateWindow(GAME_NAME, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
				     WIDTH, HEIGTH, 0);
	gd->renderer = SDL_CreateRenderer(gd->window, -1, SDL_RENDERER_ACCELERATED);
	gd->in_game = 0;
	gd->menu_lgc.pressed_space = 0;
	gd->game_lgc.player_dead = 0;
	gd->pouce.w = 150;
	gd->pouce.h = 250;
	gd->pouce.y = 720 - gd->pouce.h;
	gd->pouce.x = 300;
	gd->pouce.life = 100;
	gd->baptouiste.w = 300;
	gd->baptouiste.h = 100;
	gd->baptouiste.y = 720 - gd->baptouiste.h;
	gd->baptouiste.x = 700;
	gd->baptouiste.life = 100;
	gd->game_lgc.p1_frame = 0;
	gd->game_lgc.p1_attack = 0;
	gd->game_lgc.p2_frame = 0;
	gd->game_lgc.p2_attack = 0;
	
	return 0;
}

int loadSoundTextures(struct _game_data * inf)
{
	SDL_Color text_color = {255, 255, 255};
	
	inf->font.menu_font = TTF_OpenFont("Resources/sanstaina.ttf", 24);
	inf->music.menu_music = Mix_LoadMUS("Resources/menu_music.mp3");
	
	inf->baptuiste.surface = IMG_Load("Resources/baptousite.png");
	inf->title.surface = IMG_Load("Resources/Title.png");
	inf->menu_texture[0].surface = IMG_Load("Resources/Wall.png");
	inf->menu_texture[1].surface = IMG_Load("Resources/Wall_orteil.png");
	inf->side_wall_texture[0][0].surface = IMG_Load("Resources/Side_Wall_orteil1.png");
	inf->side_wall_texture[1][0].surface = IMG_Load("Resources/Side_Wall_orteil2.png");
	inf->side_wall_texture[0][1].surface = IMG_Load("Resources/SecSide_Wall_orteil1.png");
	inf->side_wall_texture[1][1].surface = IMG_Load("Resources/SecSide_Wall_orteil2.png");
	inf->pouce.surface[0] = IMG_Load("Resources/pouce.png");
	inf->pouce.surface[1] = IMG_Load("Resources/pouce2.png");
	inf->wallpaper.surface = IMG_Load("Resources/Map.png");
	inf->playGame.surface = TTF_RenderText_Solid(inf->font.menu_font, "Play game", text_color);
	inf->p1Win.surface = TTF_RenderText_Solid(inf->font.menu_font, "Mr pouce wins", text_color);
	inf->p2Win.surface = TTF_RenderText_Solid(inf->font.menu_font, "Baptouiste wins", text_color);
	
	if(inf->baptuiste.surface == NULL || inf->menu_texture[1].surface == NULL ||
	   inf->menu_texture[0].surface == NULL || inf->font.menu_font == NULL ||
	   inf->music.menu_music == NULL || inf->wallpaper.surface == NULL ||
	   inf->side_wall_texture[1][0].surface == NULL ||
	   inf->side_wall_texture[0][0].surface == NULL||
	   inf->title.surface == NULL || inf->side_wall_texture[1][1].surface == NULL ||
	   inf->side_wall_texture[0][1].surface == NULL || inf->pouce.surface[0] == NULL ||
	   inf->pouce.surface[1] == NULL)
		error(1, "Can't load the files!");

	inf->title.texture = SDL_CreateTextureFromSurface(inf->renderer, inf->title.surface);
	inf->baptuiste.texture = SDL_CreateTextureFromSurface(inf->renderer,
							inf->baptuiste.surface);
	inf->playGame.texture = SDL_CreateTextureFromSurface(inf->renderer, inf->playGame.surface);
	inf->p1Win.texture = SDL_CreateTextureFromSurface(inf->renderer, inf->p1Win.surface);
	inf->p2Win.texture = SDL_CreateTextureFromSurface(inf->renderer, inf->p2Win.surface);
	for(int i = 0; i < 2; i ++)
		inf->menu_texture[i].texture = SDL_CreateTextureFromSurface(inf->renderer,
								inf->menu_texture[i].surface);
	for(int i = 0; i < 2; i++)
		inf->side_wall_texture[i][0].texture = SDL_CreateTextureFromSurface(inf->renderer,
								inf->side_wall_texture[i][0].surface);
	for(int i = 0; i < 2; i++)
		inf->side_wall_texture[i][1].texture = SDL_CreateTextureFromSurface(inf->renderer,
								inf->side_wall_texture[i][1].surface);
	for(int i = 0; i < 2; i++)
		inf->pouce.texture[i] = SDL_CreateTextureFromSurface(inf->renderer,
								     inf->pouce.surface[i]);
	inf->wallpaper.texture = SDL_CreateTextureFromSurface(inf->renderer, inf->wallpaper.surface);
	
	inf->baptouiste.texture = inf->baptuiste.texture;
	
	SDL_FreeSurface(inf->p1Win.surface);
	SDL_FreeSurface(inf->p2Win.surface);
	SDL_FreeSurface(inf->title.surface);
	SDL_FreeSurface(inf->baptuiste.surface);
	for(int i = 0; i < 2; i++)
		SDL_FreeSurface(inf->menu_texture[i].surface);
	for(int i = 0; i < 2; i++)
		SDL_FreeSurface(inf->side_wall_texture[i][0].surface);
	for(int i = 0; i < 2; i++)
		SDL_FreeSurface(inf->side_wall_texture[i][1].surface);
	for(int i = 0; i < 2; i++)
		SDL_FreeSurface(inf->pouce.surface[i]);
	SDL_FreeSurface(inf->playGame.surface);
	
	
	return 0;
}

void error(int errcode, char * msg)
{
	perror(msg);
	exit(errcode);
}

void quit(struct _game_data * inf)
{
	SDL_DestroyWindow(inf->window);
	SDL_DestroyRenderer(inf->renderer);
	SDL_DestroyTexture(inf->baptuiste.texture);
	for(int i = 0; i < 2; i++)
		SDL_DestroyTexture(inf->menu_texture[i].texture);
	Mix_CloseAudio();
	TTF_Quit();
	SDL_Quit();
	
	exit(0);
}

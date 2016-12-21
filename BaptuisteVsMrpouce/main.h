//
//  main.h
//  Game
//
//  Created by Leo Smith on 29/11/2016.
//  Copyright © 2016 Leo Smith. All rights reserved.
//

#ifndef main_h
#define main_h

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"
#include "SDL2_ttf/SDL_ttf.h"
#include "SDL2_mixer/SDL_mixer.h"

#define GAME_NAME "I can suck my own DICK!"
#define WIDTH 1080
#define HEIGTH 720

/*
 * Game Texture and surface
 */

struct _baptuiste_texture {
	SDL_Surface * surface;
	SDL_Texture * texture;
};

struct _menu_wall_texture {
	SDL_Surface * surface;
	SDL_Texture * texture;
};

struct _game_wall_side_texture {
	SDL_Surface * surface;
	SDL_Texture * texture;
};

struct _game_wallpaper {
	SDL_Surface * surface;
	SDL_Texture * texture;
};

struct _game_title {
	SDL_Surface * surface;
	SDL_Texture * texture;
};

struct _game_text_playGame {
	SDL_Surface * surface;
	SDL_Texture * texture;
};

struct _game_text_p1Win {
	SDL_Surface * surface;
	SDL_Texture * texture;
};

struct _game_text_p2Win {
	SDL_Surface * surface;
	SDL_Texture * texture;
};

struct _game_fonts {
	TTF_Font * menu_font;
};

struct _game_musics {
	Mix_Music * menu_music;
	Mix_Music * sfx_menu_blip;
};

/*
 * Game logic
 */

struct _menu_logic {
	int pressed_space;
};

struct _game_logic {
	int player_dead;
	int foot_selected;
	int p1_frame;
	int p1_left;
	int p1_right;
	int p2_frame;
	int p2_left;
	int p2_right;
	int k_pressed;
	int p1_attack;
	int p2_attack;
};

struct _end_logic {
	int pWin;
};

/*
 * Players
 */

struct _player_pouce {
	int x, y;
	int w, h;
	int life;
	
	SDL_Surface * surface[2];
	SDL_Texture * texture[2];
};

struct _player_baptouiste {
	int x, y;
	int w, h;
	int life;
	
	SDL_Surface * surface;
	SDL_Texture * texture;
};

/*
 * Main data structure
 */
struct _game_data {
	
	int in_game;
	
	struct _baptuiste_texture baptuiste;
	struct _menu_wall_texture menu_texture[2];	// 0 - no iepd | 1 - iepd
	struct _game_wall_side_texture side_wall_texture[2][2];	//LEFT N RIGHT
	struct _game_wallpaper wallpaper;
	struct _game_text_playGame playGame;
	struct _game_text_p1Win p1Win;
	struct _game_text_p2Win p2Win;
	struct _game_fonts font;
	struct _game_musics music;
	struct _menu_logic menu_lgc;
	struct _game_logic game_lgc;
	struct _end_logic end_lgc;
	struct _game_title title;
	struct _player_pouce pouce;
	struct _player_baptouiste baptouiste;
	
	SDL_Window * window;
	SDL_Renderer * renderer;
	
};



void quit(struct _game_data *);
void error(int , char *);
int loadSoundTextures(struct _game_data *);
int initFunc(struct _game_data *);

#endif /* main_h */

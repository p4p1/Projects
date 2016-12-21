//
//  game.h
//  Game
//
//  Created by Leo Smith on 05/12/2016.
//  Copyright © 2016 Leo Smith. All rights reserved.
//

#ifndef game_h
#define game_h

#include "main.h"

int process_controls(struct _game_data * );
int render_game(struct _game_data * , int);
int game_logic(struct _game_data * );
int render_map(struct _game_data * , int );
int render_player(struct _game_data *, int);
int check_attack(struct _game_data *);
int render_life(struct _game_data *);
void gravity(struct _game_data *);

#endif /* game_h */

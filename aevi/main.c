#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <time.h>

#define NUMOENE 100

typedef struct _WIN_struct {

	int enex[NUMOENE], eney[NUMOENE];
	int startx, starty;
	int height, width;

}WIN;

int row, col;

void printEnemy(WIN * p_win);
void init_win_params(WIN *p_win, int * Score);
void print_win_params(WIN *p_win);
void create_box(WIN *win, bool flag);
void printDisplay(int Score);
void my_delay(int i);

int main(int argc, char *argv[])
{
	WIN win;
	int ch;
	int Score;
	int br = 0;

	initscr();			/* Start curses mode 		*/
	start_color();			/* Start the color functionality */
	cbreak();			/* Line buffering disabled, Pass on
					 * everty thing to me 		*/
	keypad(stdscr, TRUE);		/* I need that nifty F1 	*/
	nodelay(stdscr, TRUE);
	noecho();
	curs_set(0);

	/* Initialize the window parameters */
	init_win_params(&win, &Score);
	print_win_params(&win);
	printDisplay(Score); 
	create_box(&win, TRUE);
	
	while((ch = getch()) != KEY_F(1) && !br)
	{
		printDisplay(Score);
		printEnemy(&win);
		switch(ch)
		{	case KEY_LEFT:
				if(win.startx > (LINES/2) + 1){
					create_box(&win, FALSE);
					--win.startx;
					create_box(&win, TRUE);
					break;
				}
			case KEY_RIGHT:
				if(win.startx < (LINES*2+(LINES/2))-1) {
					create_box(&win, FALSE);
					++win.startx;
					create_box(&win, TRUE);
					break;
				}
		}

		for(int i = 0; i < NUMOENE; i++){
			if(win.startx == win.enex[i] && win.starty == win.eney[i])
				br = 1;
			else if(win.starty == win.eney[i])
				Score++;
		}
		my_delay(100);

	}
	endwin();			/* End curses mode		  */
	printf("Score : %d\n", Score);
	return 0;
}
void init_win_params(WIN *p_win, int * Score)
{
	getmaxyx(stdscr, row, col);
	p_win->height = 2;
	p_win->width = 1;
	p_win->starty = LINES - p_win->height;	
	p_win->startx = (COLS - p_win->width)/2;
	*Score = 0;

	for(int i = 0; i < NUMOENE; i++){
        	do {
        		p_win->eney[i] = rand()% 20;
        	        p_win->enex[i] = rand() % (LINES*2+(LINES/2));
		} while (!(p_win->enex[i] > (LINES/2) && p_win->enex[i] < ((LINES*2+(LINES/2))-1)));
	}
}
void print_win_params(WIN *p_win)
{
#ifdef _DEBUG
	mvprintw(25, 0, "%d %d %d %d", p_win->startx, p_win->starty, 
			p_win->width, p_win->height);
	refresh();
#endif
}
void create_box(WIN *p_win, bool flag)
{	int i, j;
	int x, y, w, h;

	x = p_win->startx;
	y = p_win->starty;
	w = p_win->width;
	h = p_win->height;

	if(flag == TRUE) {
		mvaddch(y, x, '^');
	}
	else
		for(j = y; j <= y + h; ++j)
			for(i = x; i <= x + w; ++i)
				mvaddch(j, i, ' ');
				
	refresh();

}

void printDisplay(int Score)
{
	getmaxyx(stdscr, row, col);

	init_pair(1, COLOR_CYAN, COLOR_BLACK);
	init_pair(2, COLOR_WHITE, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	
	attron(COLOR_PAIR(1));
        mvprintw(0, 0," F1 to exit");
        attroff(COLOR_PAIR(1));


	attron(COLOR_PAIR(2));
	for(int i = 0; i < COLS; i++) {
                mvprintw(i, LINES/2, "|");
        }
        for(int i = 0; i < COLS; i++) {
                mvprintw(i, LINES*2+(LINES/2), "|");
        }
	attroff(COLOR_PAIR(2));

	attron(COLOR_PAIR(3));
	mvprintw((row)-(row-1), col-2, "%d", Score);
	attroff(COLOR_PAIR(3));
}

void printEnemy(WIN * p_win)
{
	getmaxyx(stdscr, row, col);
	for(int i = 0; i < NUMOENE; i++){
		p_win->eney[i]++;
		if(p_win->eney[i] > row){
			do {
				p_win->eney[i] = rand()% 20;
        	        	p_win->enex[i] = rand() % (LINES*2+(LINES/2));
        		} while (!(p_win->enex[i] > (LINES/2) && p_win->enex[i] < ((LINES*2+(LINES/2))-1)));
		}
		mvprintw(p_win->eney[i], p_win->enex[i], "*");
		mvprintw(p_win->eney[i]-1, p_win->enex[i], " ");
	}
	refresh();
}

void my_delay(int i)    /*Pause l'application pour i ms*/
{
    clock_t start,end;
    start=clock();
    while(((end=clock())-start)<=((i*CLOCKS_PER_SEC)/1000));
}

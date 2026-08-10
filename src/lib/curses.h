typedef struct WINDOW WINDOW;


#define ERR (-1)

#define COLS 80
#define LINES 25

#define OK (0)

#define TRUE 1
#define FALSE 0


static WINDOW* stdscr;


int mvaddch(int y, int x, const char ch);

void initscr(void);

int noecho(void) { return OK; }

int curs_set(int visibility) { return OK; }

int getch(void) { return ERR; }

int nodelay(WINDOW *win, int bf) { return OK; }

int leaveok(WINDOW *win, int bf) { return OK; }

int scrollok(WINDOW *win, int bf) { return OK; }

int refresh(void) { return OK; }
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

int curs_set(int) { return OK; }

int getch(void) { return ERR; }

int nodelay(WINDOW*, int) { return OK; }

int leaveok(WINDOW*, int) { return OK; }

int scrollok(WINDOW*, int) { return OK; }

int refresh(void) { return OK; }

int mvcur(int, int, int, int) { return OK; }

int endwin(void) { return OK; }
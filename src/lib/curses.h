#define ERR (-1)

#define COLS 80
#define LINES 25

#define OK (0)

int mvaddch(int y, int x, const char ch);

void initscr(void);

int noecho(void) { return OK; };

int curs_set(int visibility) { return OK; }
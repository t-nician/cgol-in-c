#ifndef CGOL_GRID
#define CGOL_GRID

#define LIVE_CELL_CHAR 'X'
#define DEAD_CELL_CHAR ' '

#define GRID_ROW_MAX 10000
#define GRID_COLUMN_MAX 10000


extern char **grid;

extern int current_row_size;
extern int current_column_size;

void printGrid();
void cleanupGrid();

void setupGrid(int row_size, int column_size);
char indexGrid(int row, int column);

char createRandomCell();

#endif
#include <stdlib.h>

#include "cgol_grid.h"
#include "cgol_logic.h"


int countNeighbors(int row, int column) {
    int count = 0;

    if (grid[row][column] == LIVE_CELL_CHAR) {
        count--;
    }

    for(int row_offset = -1; row_offset < 2; row_offset++) {
        for(int column_offset = -1; column_offset < 2; column_offset++) {
            char neighbor = indexGrid(
                row + row_offset, 
                column + column_offset
            );

            if(neighbor == LIVE_CELL_CHAR) {
                count++;
            }
        }
    }

    return count;
}


void updateGrid() {
    int increase_by = sizeof(int) * 2;

    int *kills = malloc(increase_by);
    int *revives = malloc(increase_by);

    int kill_size = 0;
    int revive_size = 0;


    for(int row = 0; row < current_row_size; row++) {
        for(int column = 0; column < current_column_size; column++) {
            char cell = indexGrid(row, column);
            int neighbors = countNeighbors(row, column);
            
            switch (cell) {
                case LIVE_CELL_CHAR:
                    if (neighbors > 3 || neighbors < 2) {
                        kills[kill_size] = row;
                        kills[kill_size + 1] = column;

                        kill_size += 2;

                        kills = realloc(
                            kills,
                            kill_size * increase_by
                        );
                    }
                    break;
                case DEAD_CELL_CHAR:
                    if (neighbors == 3) {
                        revives[revive_size] = row;
                        revives[revive_size + 1] = column;

                        revive_size += 2;

                        revives = realloc(
                            revives, 
                            revive_size * increase_by
                        );
                    }
                    break;
                default:
                    break;
            }
        }
    }

    for(int i = 0; i < revive_size; i++) {
        if (i % 2 == 0) {
            int row = revives[i];
            int column = revives[i + 1];

            grid[row][column] = LIVE_CELL_CHAR;
        }
    }

    for(int i = 0; i < kill_size; i++) {
        if (i % 2 == 0) {
            int row = kills[i];
            int column = kills[i + 1];

            grid[row][column] = DEAD_CELL_CHAR;
        }
    }


    free(kills);
    free(revives);
}
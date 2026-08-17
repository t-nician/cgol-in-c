#include <stdio.h>
#include <stdlib.h>

#include "cgol_grid.h"


char **grid = NULL;

int current_row_size = 0;
int current_column_size = 0;


char createRandomCell() {
    if (rand() % 2 == 0) {
        return LIVE_CELL_CHAR;
    } else {
        return DEAD_CELL_CHAR;
    }
}


char indexGrid(int row, int column) {
    int final_row = row;
    int final_column = column;

    if (row >= current_row_size) {
        final_row = 0;
    } else if(row < 0) {
        final_row = current_row_size - 1;
    }

    if (column >= current_column_size) {
        final_column = 0;
    } else if(column < 0) {
        final_column = current_column_size - 1;
    }

    return grid[final_row][final_column];
}


void cleanupGrid() {
    if (grid != NULL) {
        for(int row = 0; row < current_row_size; row++) {
            free(grid[row]);
        }

        free(grid);
    }

    grid = NULL;
    current_row_size = 0;
    current_column_size = 0;
}
    

void setupGrid(int row_size, int column_size) {
    cleanupGrid();

    current_row_size = row_size;
    current_column_size = column_size;

    grid = malloc(current_row_size * sizeof(*grid));

    for(int row = 0; row < current_row_size; row++) {
        grid[row] = malloc(current_column_size * sizeof(*grid));

        for(int column = 0; column < current_column_size; column++) {
            grid[row][column] = createRandomCell();
        }
    }
}


void printGrid() {
    char *buffer = malloc(
        (
            ((current_row_size + 1) * (current_column_size + 1)) + 1
        ) * sizeof(char)
    );
    
    int size = 0;

    for(int row = 0; row < current_row_size; row++) {
        for(int column = 0; column < current_column_size; column++) {
            buffer[size++] = grid[row][column];
        }

        buffer[size++] = '\n';
    }

    for(int i = 0; i < current_column_size; i++) {
        buffer[size++] = '-';
    }

    buffer[size++] = '\n';
    buffer[size++] = '\0';

    printf("%s", buffer);

    free(buffer);
}
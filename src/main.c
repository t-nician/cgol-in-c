#include <stdbool.h>
#include <windows.h>
#include <time.h>

#include "cgol_grid.h"
#include "cgol_logic.h"

// main

int main() {
    int row_size = 25;
    int column_size = 150;

    srand((unsigned int) time(NULL));

    setupGrid(row_size, column_size);

    while(!(GetAsyncKeyState('2') & 0x8000)) {
        if(GetAsyncKeyState('1') & 0x8000) { 
            setupGrid(row_size, column_size);
        }

        updateGrid();
        printGrid();

        Sleep(50);
    }

    cleanupGrid();

    return 0;
}
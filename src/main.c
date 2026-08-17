#include <stdbool.h>
#include <windows.h>
#include <winuser.h>
#include <time.h>

#include "cgol_grid.h"
#include "cgol_logic.h"


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











/*#include <Windows.h>

#include "cgol.h"

void main() {
    srand((unsigned int)time(NULL));
    
    cgolGrid grid = cgolCreateGrid(10, 50);

    while (1) {
        cgolCellUpdateList updates = cgolGetCellUpdates(&grid);

        for(int i = 0; i < updates.size; i++) {
            cgolCellUpdate update = updates.updates[i];

            grid.matrix[update.row][update.column].state = update.new_state;
        }

        cgolGridAsString string = cgolGridToString(&grid);
        printf("%s", string.data);
        printf("--------------------------------------------------\n");

        Sleep(100);
    };
}*/
#include <ncurses.h>

void testMouseCursor() {
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    mousemask(ALL_MOUSE_EVENTS, NULL); 
    MEVENT event;
    int x = 10, y = 5;  // Starting position
    mvprintw(y, x, "@");  // Print character at starting position
    refresh();

    int ch;
    while ((ch = getch()) != 'q') {  // Press 'q' to quit
        mvprintw(y, x, " ");         // Erase previous character
        switch (ch) {
            case KEY_UP:
                y = (y > 0) ? y - 1 : y;
                break;
            case KEY_DOWN:
                y = (y < LINES - 1) ? y + 1 : y;
                break;
            case KEY_LEFT:
                x = (x > 0) ? x - 1 : x;
                break;
            case KEY_RIGHT:
                x = (x < COLS - 1) ? x + 1 : x;
                break;
            case KEY_MOUSE:
                if (getmouse(&event) == OK) {
                    mvprintw(2, 2, "M");
                    if (event.bstate & BUTTON1_CLICKED) {
                        x = event.x;
                        y = event.y;
                        
                    } else if (event.bstate & BUTTON3_CLICKED) {
                        x = event.x;
                        y = event.y;
                    }
                }
                break;
        }
        mvprintw(y, x, "@"); 
        refresh();
    }

    endwin();
}
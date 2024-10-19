#include <ncurses.h>



/// @brief 
void testSimpleWindow(){
    initscr();
    WINDOW *win = newwin(15, 17, 2, 10);
    refresh();
    box(win, 0, 0);
    mvwprintw(win, 0, 1, "Greeter");
    mvwprintw(win, 1, 1, "Hello");
    wrefresh(win);
    getch();
    clear();
    endwin();
}


/// @brief testing code for keyboard and mouse interaction with ncurses
void testKbdAndMouseCursor() {
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
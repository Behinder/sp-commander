#include <ncurses.h>

int main() {
   // 1. Initialize the NCurses screen
       initscr(); // Start NCurses mode 
       printw("Czesc Przemek to będzie twoja fajna aplikacja");

       // refresh screen to show message
       refresh();

       // wait for user input
       getch();

       //end NCurses mode
       endwin();
       return 0;

}
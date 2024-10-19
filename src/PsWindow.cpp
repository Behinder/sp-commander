#include <iostream>
#include <vector>
#include <string>

class PSWindow {
public:
    char* title;
    PSWindow(const std::string& title){}
    void show() {
        std::cout << "Showing window: " << title << std::endl;
    };
};


class TiledView {
public:
    std::vector<PSWindow> windows; // Vector of PSWindow

    void addWindow(PSWindow& window) {
        windows.push_back(window);
    };

    void showAllWindows(){
        for (PSWindow& window : windows) {
        window.show();
        }
    };
};

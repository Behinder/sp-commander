#include <iostream>
#include <vector>
#include <string>

class PSStatusBar{

};
class PSMenuBar{

};

class PSWindow {
public:
    char* title;
    PSWindow(const std::string& title){}
    virtual void show() {
        
    };

    virtual ~PSWindow() = default;
};

class ExplorerWindow : public PSWindow {
    public:
    ExplorerWindow(const std::string& title) : PSWindow(title) {}

    void show() override {
        PSWindow::show();
    }
};

class EditorWindow : public PSWindow{
    public:
    EditorWindow(const std::string& title) : PSWindow(title) {}

    void show() override {
        PSWindow::show();
    }
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

class PSScreen{
    public:
    PSMenuBar MenuBar;
    TiledView MainView;
    PSStatusBar StatusBar;
};

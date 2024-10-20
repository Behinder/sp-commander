#include <iostream>
#include <vector>
#include <string>

class PSWindow {
public:
    char* title;
    PSWindow(const std::string& title){}
    virtual void show() {
        
    };

    virtual ~PSWindow() = default;
};

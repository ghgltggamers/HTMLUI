#include "HTMLUI.h"
#include <iostream>

int main() {
    HTMLUI ui("Sample App", 800, 600);

    ui.loadHTML("<html><body><h1>Hello, HTML UI!</h1><button onclick=\"callNative()\">Call Native</button>"
    "<script>"
    "function callNative() {"
    "    window.webkit.messageHandlers.nativeCallback.postMessage('greet:Hello from JS!');"
    "}"
    "</script>"
    "</body></html>");

    ui.registerFunction("greet", [](const std::string& message) {
        std::cout << "JavaScript called greet with message: " << message << std::endl;
    });

    ui.run();
    return 0;
}

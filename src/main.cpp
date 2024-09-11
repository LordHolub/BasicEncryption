#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <string>

using namespace ftxui;
using namespace std;

int main(){
    string str;

    Component input_first_string = Input(&str, "Encryption string");

    auto component = Container::Vertical({
        input_first_string,
    });

    auto renderer = Renderer(component, [&]{
        return hbox({ text(" Encryption string : "), input_first_string->Render(), }) | border;
    });

    ScreenInteractive::Fullscreen().Loop(renderer);
    
    return EXIT_SUCCESS;
}
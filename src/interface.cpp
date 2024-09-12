#include "headers.h"

void Interface::CreateInterface(string &rstr){
    string encryption_step;
    string encrypted_str;

    Component input_first_string = Input(&rstr, "Encryption string");
    Component input_encryption_step = Input(&encryption_step, "Encryption step");
    Component input_second_string = Input(&encrypted_str, "Decryption string");
    //Component input_encryption_step = Input(&encryption_step, "Encryption step");


    auto component = Container::Vertical({
        input_first_string,
        input_encryption_step,
        input_second_string,
    });



    auto renderer = Renderer(component, [&]{
        return vbox({ 
            hbox({ 
                hbox({text(" Simple replacement. Encryption string : "), input_first_string->Render() | flex, }), 
                hbox({text(" Encryption step : "), input_encryption_step->Render(), }),
                }) | border,
            hbox({text(" Decryption string : "), input_second_string->Render()}) | border,
            separator(),
            hbox({text( "Output encryption : " + Encryption::RSimpleReplacement(rstr, 3)), text( "Output decryption : " + Encryption::LSimpleReplacement(encrypted_str, 3)) }),
        }) | border;
    });

    ScreenInteractive::Fullscreen().Loop(renderer);
}


Interface::Interface(){}
Interface::~Interface(){}
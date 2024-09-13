#include "headers.h"

void Interface::CreateInterface(string &rstr){
    string encryption_step;
    string encrypted_str;
    vector<string> tab_values {
        "Simple replacment",
        "Polybius square",
    };
    int tab_selected = 0;
    auto tab_toggle = Toggle(&tab_values, &tab_selected);

    Component input_first_string = Input(&rstr, "Encryption string");
    Component input_encryption_step = Input(&encryption_step, "Encryption step");
    Component input_second_string = Input(&encrypted_str, "Decryption string");
    //Component input_encryption_step = Input(&encryption_step, "Encryption step");

    auto tab_container = Container::Tab({
        Renderer([&]{ return vbox({ 
            hbox({ 
                hbox({text(" Encryption string : "), input_first_string->Render(), }), 
                hbox({text(" Encryption step : "), input_encryption_step->Render(), }),
                }),
            hbox({text(" Decryption string : "), input_second_string->Render()}),
            separator(),
            hbox({text( "Output encryption : " + Encryption::SimpleReplacement(rstr, ToNumber(encryption_step))),}),
            hbox({text( "Output decryption : " + Encryption::SimpleReplacement(encrypted_str, -(ToNumber(encryption_step)))),}),
        }) | border; }),
        Renderer([]{ return text("Empty lines...."); }),
    }, &tab_selected);

    auto component = Container::Vertical({
        tab_toggle,
        tab_container,
        input_first_string,
        input_encryption_step,
        input_second_string,
    });



    auto renderer = Renderer(component, [&]{
        return vbox({
            tab_toggle->Render(),
            separator(),
            tab_container->Render(),
        }) | border;
    });

    ScreenInteractive::Fullscreen().Loop(renderer);
}

int Interface::ToNumber(string &str_number){
    int number;
    string digit = "";

    for(char ch : str_number){
        if(isdigit(ch))
            digit += ch;
    }
    if(digit != "")
        number = stoi(digit);
    else
        number = 0;
    return number;
}


Interface::Interface(){}
Interface::~Interface(){}
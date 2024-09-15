#include "headers.h"

void Interface::CreateInterface(){
    string rstr;
    string encryption_step;
    string encrypted_str;
    vector<string> tab_values {
        "Simple replacment",
        "Polybius square",
        "Cipher Permutation",
        "Cipher Trithemius",
    };
    int tab_selected = 0;
    auto tab_toggle = Toggle(&tab_values, &tab_selected);

    //Input first tab
    Component input_first_string = Input(&rstr, "Encryption string");
    Component input_encryption_step = Input(&encryption_step, "Encryption step");
    Component input_second_string = Input(&encrypted_str, "Decryption string");
    //Input second tab
    string str_polibyus;
    string encryption_polibyus;
    Component input_encryption_polibyus = Input(&str_polibyus, "String for encryption");
    Component input_decryption_polibyus = Input(&encryption_polibyus, "String for decryption");
    //Input third tab
    string str_permutation;
    string encryption_permutation;
    Component input_encryption_permutation = Input(&str_permutation, "String for permutation");
    Component input_decryption_permutation = Input(&encryption_permutation, "String for decryption");
    //Input fourth tab
    string str_trethemius;
    string encryption_trethemius;
    string shift;
    Component input_encryption_trethemius = Input(&str_trethemius, "String for encryption");
    Component input_decryption_trethemius = Input(&encryption_trethemius, "String for decryption");
    Component input_shift = Input(&shift, "Trethemius shift");

    //tabs contents
    auto tab_container = Container::Tab({
        Renderer([&]{ return vbox({ //tab simple replacment
            hbox({ 
                hbox({text(" String for encryption : "), input_first_string->Render(), }), 
                hbox({text(" Step for encryption : "), input_encryption_step->Render(), }),
                }),
            hbox({text(" String for decryption : "), input_second_string->Render()}),
            separator(),
            hbox({text( "Output encryption : " + Encryption::SimpleReplacement(rstr, ToNumber(encryption_step))),}),
            hbox({text( "Output decryption : " + Encryption::SimpleReplacement(encrypted_str, -(ToNumber(encryption_step)))),}),
        }) | border; }),
        Renderer([&]{ return vbox({ //tab polibyus square
            hbox({text(" String for encryption : "), input_encryption_polibyus->Render(), }),
            hbox({text(" String for decryption : "), input_decryption_polibyus->Render(), }),
            separator(),
            hbox({text("Output encryption : " + Encryption::PolibyusSquare(str_polibyus)),}),
            hbox({text("Output decryption : " + Encryption::DePolibyusSquare(encryption_polibyus)),}),
        }) | border; }),
        Renderer([&]{ return vbox({ //tab permutation
            hbox({text(" String for permutation : "), input_encryption_permutation->Render(),}),
            hbox({text(" String for decryption : "), input_decryption_permutation->Render(), }),
            separator(),
            hbox({text("Output encryption : " + Encryption::CipherPermutation(str_permutation)),}),
            hbox({text("Output decryption : " + Encryption::CipherPermutation(encryption_permutation)),}),
        }) | border; }),
        Renderer([&]{ return vbox({ //tab trethemius
            hbox({text(" String for encryption : "), input_encryption_trethemius->Render(),}),
            hbox({text(" Shift for trethemius encryption : "), input_shift->Render(),}),
            hbox({text(" String for decryption : "), input_decryption_trethemius->Render(),}),
            separator(),
            hbox({text("Output encryption : " + Encryption::CipherTrithemius(str_trethemius, static_cast<short>(ToNumber(shift)))),}),
            hbox({text("Output encryption : " + Encryption::CipherTrithemius(encryption_trethemius, static_cast<short>(ToNumber(shift)), true)),}),
        }) | border; }),
    }, &tab_selected);

    auto component = Container::Vertical({
        tab_toggle,
        tab_container,
        input_first_string,
        input_encryption_step,
        input_second_string,
        input_encryption_polibyus,
        input_decryption_polibyus,
        input_encryption_permutation,
        input_decryption_permutation,
        input_encryption_trethemius,
        input_decryption_trethemius,
        input_shift,
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
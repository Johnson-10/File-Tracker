#include "FileTrackerView.h"
#include <iostream>

namespace FileTrackerView::View{



    void UI::Menu(){
        std::cout<<"\t\t\t\t BEM VINDO AO FILE TRACKER \t\t"<<std::endl;
        std::cout<<"\t\t AQUI PODES MONITORAR UMA PASTA PARA RASTREAR EM TEMPO REAL\t\t\n"<<std::endl;
    }

    /* mostrar a informacao na tela*/
    void UI::prompt(std::string s){
        std::cout<<"\t\t"<<s;
    }
    /* Ler a informacao na tela*/
    std::string UI::getInput(){
        std::string s; // lear na tela
        getline(std::cin,s);
        return s;
    }     
};

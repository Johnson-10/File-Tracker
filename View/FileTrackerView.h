#ifndef VIEW_H
#define VIEW_H
#include <string>
#include <locale>

namespace FileTrackerView::View{

    class UI{
        public:
            /*Menu*/
            void Menu();
            /* mostrar a informacao na tela*/
            void prompt(std::string);
            /* Ler a informacao na tela*/
            std::string getInput();     
   };
};

#endif
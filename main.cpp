/*
    A primeira parte do File Tracker rastrea os ficheiros em uma pasta

    verifica quando foram abertos e quando foram fechados!

    Nao verifica a pastas somente files e a quantidade de bytes existentes



*/


#include <iostream>
#include "View/FileTrackerView.h"
#include "Controller/FileTrackerController.h"



int main(){
    FileTrackerView::View::UI ui;
    FileTrackerController::Controller::FT_Controller FT_Controller(&ui);

    std::system("Pause");
    return 0;    
}
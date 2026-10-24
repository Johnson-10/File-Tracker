#include <iostream>
#include "View/FileTrackerView.h"
#include "Controller/FileTrackerController.h"



int main(){
    FileTrackerView::View::UI ui;
    FileTrackerController::Controller::FT_Controller FT_Controller(&ui);

    std::system("Pause");
    return 0;    
}
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../View/FileTrackerView.h"
#include <filesystem>
#include <vector>


namespace FileTrackerController::Controller{
    struct File_Path{
        std::string filePath;
        long long unsigned int byte;
    };
    class FT_Controller{
        private:
            FileTrackerView::View::UI* view;
            std::string directorio;
            std::filesystem::path dir; // directorio;
            std::vector<File_Path> directorios; // lista de directorios
            int qtd_file=0;
            
        public:
            FT_Controller(FileTrackerView::View::UI *ui);
            /* calcular byte*/
            std::string calcularByte(long long unsigned int byte);
            /*quntidade de ficheiros*/
            int getQtd_file();
            /*funcao get listar ficheiros por pasta*/
            std::vector<File_Path> getListFile();

             /*funcao listar ficheiros por pasta*/
            void ListFile();

            /*funcao verificar por pasta*/
            void verificarL_Path();

            /*funcao verificar a existencia do ficheiros por pasta*/
            bool isPath();

            /*funcao setDir na biblioteca filesystem*/
            void setDir(std::string );

            /*funcao getDir na biblioteca filesystem*/
            std::filesystem::path getDir();
            
            /*funcao getdirectorio*/
            void setDirectorio(std::string );

            /*funcao getdirectorio*/
            std::string getDirectorio();
           
   };
};

#endif
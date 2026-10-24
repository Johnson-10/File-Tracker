
#include "FileTrackerController.h"
#include <iostream>
#include <cmath>
#include <regex>



namespace FileTrackerController::Controller{

    FT_Controller::FT_Controller(FileTrackerView::View::UI *ui) {
        ui->Menu();
        ui->prompt("Informe o directorio para o rastreo: ");
        this->directorio=ui->getInput();
        FT_Controller::setDir(this->directorio);
        ui->prompt("\n");
        FT_Controller::verificarL_Path();

        FT_Controller::ListFile();

    }

    /* calcular byte*/
    std::string FT_Controller::calcularByte(long long unsigned int byte){
        int qtd=0;
        float byte_conversor=byte; // converter bystes
        
        std::string unidade=""; // escrever unidades
        while(true){
            if(byte_conversor>999){
                qtd++;
            }else break;
            byte_conversor=byte_conversor/1000.00;
        }
        switch(qtd){
            case 0: 
                unidade="B";
                break;
            case 1: 
                unidade="kB";
                break;
            case 2:
                unidade="MB";
                break;
            case 3:
                unidade="GB";
                break;
            case 4:
                unidade="TB";
                break;
        }
        std::string s_=std::to_string(round(byte_conversor));  // eliminar zeros
        return std::regex_replace(s_,std::regex("000"),"0")+" "+unidade; // eliminar zeros+unidade;
       
    }
    /*quntidade de ficheiros*/
    int FT_Controller::getQtd_file(){ 
        return this->qtd_file;
    };

    /*funcao get listar ficheiros por pasta*/
    std::vector<File_Path> FT_Controller::getListFile(){
        /*  criar um interador dos arquivos na pasta*/
        std::filesystem::directory_iterator Start{FT_Controller::getDir()};
        std::filesystem::directory_iterator End{};
        File_Path directorioName;
        this->qtd_file=0;
        for(auto Iter{Start}; Iter!= End; ++Iter){

            directorioName.filePath=Iter->path().string();
            if(Iter->is_directory()){
                 directorioName.byte=0;
            }else
                directorioName.byte=std::filesystem::file_size(Iter->path());
            
            this->directorios.push_back(directorioName);
            this->qtd_file+=1;
           
        }
        
        return this->directorios;

    }

     /*funcao listar ficheiros por pasta*/
    void FT_Controller::ListFile(){

        view->prompt("Por favor verifique os resultados que encontramos \n");
       
        for(auto file: FT_Controller::getListFile()){
            view->prompt(file.filePath + " ("+ FT_Controller::calcularByte(file.byte)+")\n");
        }
         view->prompt("\n\t\tQuantidade de Arquivos - "+ std::to_string(getQtd_file())+"\n");
    }

    /*funcao verificar por pasta*/
    void FT_Controller::verificarL_Path(){
         
        view->prompt("Nome do directorio: "+this->directorio+"\t\n");
        if( FT_Controller::isPath()){
            view->prompt("A pasta existe e esta pronta para ser monitorar\n");            
        }else{
            view->prompt("A pasta nao existe!!!"+dir.string()+"\n");
            FT_Controller::getDir(); 
        }
    }

    /*funcao setDir na biblioteca filesystem*/
    void FT_Controller::setDir(std::string s){
        this->dir=s;
    }

    /*funcao getDir na biblioteca filesystem*/
    std::filesystem::path FT_Controller::getDir(){
        return this->dir;
    }


    void FT_Controller::setDirectorio(std::string s){
        this->directorio=s.replace(s.begin(),s.end(),"\\","\\\\");
    }
    
    std::string FT_Controller::getDirectorio(){
        return this->directorio;
    }

    bool FT_Controller::isPath(){
        return getDir().has_filename();
    }
    
};
#include "fileManager.h"

FileManager::FileManager(){
    startOptions.push_back("Arcade");
    startOptions.push_back("NES");
    startOptions.push_back("Game Boy Colour");
    startOptions.push_back("Sega Mega Drive");
    startOptions.push_back("Shut Down");

    mameCommand = "./mame";
    messCommand = "./messBin/bin/advmess nes -cart ";
    gambatteCommand = "./gambatte -i return backspace z x up down left right ";
    picoCommand = "./pico";
    shutdownCommand = "./shutdown.sh";

    nesDir = "messBin/share/advance/image/nes/";
    gbcDir = "GBC/";
    nesExtension = ".nes";
    gbcExtension = ".gbc";
}

FileManager::~FileManager(){
}

void FileManager::start(){
    selection = GUI(startOptions).run();

    if (selection == -1){
        return;
    }

    switch (selection){
        case(0):
            //Arcade games. Run MAME
            std::cout << "MAME" << std::endl;

            try{
                system(mameCommand.c_str());
            }
            catch(...){
                std::cout << "System command failed." << std::endl;
            }

            break;
        case(1):
            //NES Games. Run MESS.
            std::cout << "MESS" << std::endl;

            gameSelection = chooseGame(nesDir, nesExtension);

            if (gameSelection == "NULL"){
                start();
                return;
            }

            rom = gameSelection + nesExtension;

            try{
                system((messCommand + '"' + rom + '"').c_str());
            }
            catch(...){
                std::cout << "System command failed." << std::endl;
            }

            break;
        case(2):
            //GBC Games. Run Gambatte.
            std::cout << "Gambatte" << std::endl;

            gameSelection = chooseGame(gbcDir, gbcExtension);

            if (gameSelection == "NULL"){
                start();
                return;
            }

            rom = gbcDir + gameSelection + gbcExtension;

            try{
                system((gambatteCommand + '"' + rom + '"').c_str());
            }
            catch(...){
                std::cout << "System command failed." << std::endl;
            }

            break;
        case(3):
            //Mega Drive Games. Run PicoDrive.
            std::cout << "PicoDrive" << std::endl;

            try{
                system((picoCommand).c_str());
            }
            catch(...){
                std::cout << "System command failed." << std::endl;
            }

            break;
        case(4):
            std::cout << "Shut Down" << std::endl;
            system(shutdownCommand.c_str());
            break;
    }

    start();
}

std::string FileManager::chooseGame(std::string dir, std::string extension){
    glob_t globbuf;
    int err = glob((dir + "*" + extension).c_str(), 0, NULL, &globbuf);

    if (err != 0){
        throw;
    }

    std::vector<std::string> options;

    for (size_t i = 0; i < globbuf.gl_pathc; i++){
        options.push_back(globbuf.gl_pathv[i]);
        options[i].erase(0, dir.size());
        options[i].erase(options[i].size() - extension.size(), extension.size());
    }

    globfree(&globbuf);

    int n = GUI(options, 24, true).run();

    if (n == -1){
        return "NULL";
    }

    return options[n];
}

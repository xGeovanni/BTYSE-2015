#include <iostream>
#include <stdlib.h>
#include <glob.h>
#include <vector>
#include <string>

#include "GUI.h"

class FileManager{
    int selection;
    std::vector<std::string> startOptions;

    std::string mameCommand;
    std::string messCommand;
    std::string gambatteCommand;
    std::string picoCommand;
    std::string shutdownCommand;

    std::string nesDir;
    std::string gbcDir;
    std::string nesExtension;
    std::string gbcExtension;

    std::string gameSelection;
    std::string rom;

public:
    FileManager();
    ~FileManager();
    void start();
    std::string chooseGame(std::string dir, std::string extension);
};

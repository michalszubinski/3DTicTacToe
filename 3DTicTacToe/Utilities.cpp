#include "Utilities.h"

void Utilities::PrintConsoleBoard(std::shared_ptr<Map> argMap)
{ 
    // Y level splitter
    std::string yLvlSplitter = "---";
    for (int i = 1; i <= argMap->_xDimensions - 1; ++i)
        yLvlSplitter = "---|" + yLvlSplitter;


    char tmpChar = ' ';
    for (int k = 1; k <= argMap->_zDimensions; ++k)
    {
        std::cout << "Z = " << k ;
        for (int j = 1; j <= argMap->_yDimensions; ++j)
            std::cout << "   ";
        std::cout << "X\n"; // Upper right corner X

        // Printing for each level
        for (int i = 1; i <= argMap->_xDimensions; ++i)
        {
            for (int j = 1; j <= argMap->_yDimensions; ++j)
            {
                if(j==1)std::cout << "  "; // Shift the board two spaces to the left
                if (argMap->CheckIfPositionExists(Position(i, j, k))) tmpChar = argMap->_symbols[Position(i, j, k)]._symbol;
                else tmpChar = 0x20; // Space symbol

                std::cout << " " << tmpChar << " ";
                if (j < argMap->_yDimensions) std::cout << "|";
                else std::cout << " " << i; // Show X at the end of the line
            }
            std::cout << std::endl;
                if (i < argMap->_xDimensions) std::cout << "  "<< yLvlSplitter <<"    " << std::endl;
        }
        std::cout << std::endl << "Y "; // Lower left corner Y
        for (int j = 1; j <= argMap->_yDimensions; ++j)
            std::cout << " " << j << "  "; // Show Y at the bottom
        if (k < argMap->_zDimensions) std::cout << "\n######################\n"; // End of the Z
    }
}

Position Utilities::InputCoordinatesConsole()
{
    std::string input;
    std::cout << "Enter the coordinates (x y z): ";
    std::getline(std::cin, input);

    int x, y, z;

    std::istringstream iss(input);
    if (iss >> x >> y >> z)
    {
        Position pos(x, y, z);
        return pos;
    }
    else
    {
        // Invalid input
        return Position(-1, -1, -1);
    }
}

void Utilities::ClearScreen()
{
#if defined _WIN32
    system("cls");
    //clrscr(); // including header file : conio.h
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
    //std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences 
#elif defined (__APPLE__)
    system("clear");
#endif
}

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>

//complete

int main(int argc, char** argv){
    if (argc < 4){
        std::cout << "Enter two numbers for the max value of x and y coordinates (respectively) that will be generated. Last number is the amount of coords generated";
    //takes three numbers in command line.
    }
    const int max_x = std::stoi(argv[1]);
    const int max_y = std::stoi(argv[2]);
    const int coord_amt = std::stoi(argv[3]);
    int rand_x;
    int rand_y;

    srand (time(NULL)); //random seed.

    std::ofstream file_("coords.txt"); //output file .txt

    for (int i = 0; i < coord_amt; i++){
        rand_x = rand() % max_x; //random value ranges from 0 - max_x
        rand_y = rand() % max_y; //random value ranges from 0 - max_y
        file_ << rand_x << " " << rand_y;
        if (i != coord_amt - 1)
        {
            file_ << "\n";
        }
    }

    file_.close();

    return 0;
}
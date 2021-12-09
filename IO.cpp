
#include"IO.hpp"

IO::IO(int num_points, int num_k , std::vector<int>max_dim_vec): 
num_points(num_points) , num_k(num_k) , max_dim_vec(max_dim_vec){} //IO Constructor

// --------------------------------------------------------------

IO::~IO(){} //IO Deconstructor

// --------------------------------------------------------------

void IO::write_dataset()
{
    srand (time(NULL)); //random seed.

    std::ofstream file_("datapoints.txt"); //Making the output file stream, sai=ving in directory with name "datapoints.txt"

    for (int i = 0; i < num_points; i++)//for number of points times
    {
        std::vector<int>temp_vec;//A temp vector for coordinates of each point

        for (int j = 0 ; j < max_dim_vec.size() ; j++)//for k times
        {
            temp_vec.push_back(rand() % (max_dim_vec[j] + 1)) ; //random value ranges from 0 - max_x push back to vector of a point
        }
        for (int k = 0 ; k < temp_vec.size() ; k++)//for every coordinate of a point
        {
            file_ << temp_vec[k] << " " ; //Then we put the contents of temp vector of point to the file with space between 
        }
        if (i != num_points - 1)//if it is not the last point add a space
        {
            file_ << "\n";
        }
    }
    file_.close();//Closing file stream
}

// --------------------------------------------------------------

void IO::ReadFile()
{ 
    std::ifstream file("datapoints.txt");//Making input file stream from "datapoints.txt" in the directory

    std::string str; // Temporary string to hold a single line of the file

    while (std::getline(file, str)) // Reads all lines in the file, 1 at at time
    { 
    std::vector<int> new_row; // Creates a temporary vector to represent one row

    std::istringstream ss(str); // Converts our string into a stringstream

    int token; // Temp int to store a converted value from a line

    while(ss >> token)// Reads all values from the stringstream (current row), converts to int
    { 
        new_row.push_back(token); // Adds the converted value to the row
    }
    coord_data.push_back(new_row); // Pushes our constructed vector of ints to the 2D vector
    }
}

// --------------------------------------------------------------
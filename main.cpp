
// Libraries.........................................................................................................................

#include"KDTREE.hpp"

// FUNCTION DECLARATION...............................................................................................................

void write_dataset (int max_x, int max_y, int num_points); //  A function to creste random dataset
/* Later we can make this function flexible to produce data points for any numner of dimenstion,
based on the number of input entered by the user. e.g. If three argments are entered the first two
are x and y, and the third one is "num_points". If four argments are entered the first three
are x, y and z, and the forth one is "num_points".The last argument could always be "num_points"
and all previous arguments are max values for flexible number of dimentions (k dimensions)
"k" is the number of dimensions could be determined here.
*/


void ReadFile(std::string in_fname, std::vector<std::vector<double>> *const coord_data); //  A function to read from the input text file





//Main File..........................................................................................................................

int main(){

    // Defining variables

    int max_x, max_y, num_points; //maximum longitude, maximum latitude, number of data points

    std::string in_fname; //input file name

    std::vector<std::vector<double>> coord_data; // A 2-d vector to store coord data points

    std::vector<double>new_ptn_vec;//A vector for the new point we want to test in prediction phase

    std::vector<double>max_dim_vec; //A vector to store maximum values permitted by the user for each dimention

    // Gettinf input data from user

    std::cout<< "Please enter values for the maximum longitude, maximum latitude and number of data points, repectively and seperated by space:";

    std::cin>> max_x >> max_y >> num_points; // Requesting values for the parameters of "dataset" generator function


    std::cout<<"Please enter a number, or numbers separated by a space, between zero and "

    for (int i = 0 ; i < max_dim_vec.size() ; i++){

        std::cout<<max_dim_vec[i]<<std::cout<<", ";
    }
    std::cout<< " for the dimentions respectively, to find the closest point to that:"<< std::endl;

    for (int i = 0 ; i < k ; i++){
        cin >> num;
        new_ptn_vec.push_back (num);
    }





    std::cin>>

    // Calling helper functions

    write_dataset (int max_x, int max_y, int num_points);// Making random dataset

    ReadFile(std::string in_fname, std::vector<std::vector<double>> *const coord_data);// Reading data from input text file

    // Making a KDTREE Object and calling corresponding methods

    KDTREE kdt_obj;

    // Constructing the tree-structure using produced coord_data in previous steps

    kdt_obj.construct_tree(coord_data)

    // Searching for the Nearest neighbor (point)

    kdt_obj.nn(new_ptn_vec);

    //


}



// FUNCTIONS DEFINITIONS............................................................................................................


    void ReadFile(std::string in_fname, std::vector<std::vector<double>> *const coord_data){

        std::ifstream file(in_fname);

        std::string str; // Temporary string to hold a single line of the file

        while (std::getline(file, str)) { // Reads all lines in the file, 1 at at time

        std::vector<double> new_row; // Creates a temporary vector to represent one row

        std::istringstream ss(str); // Converts our string into a stringstream

        double token; // Temp double to store a converted value from a line


            while(ss >> token){ // Reads all values from the stringstream (current row), converts to double

                new_row.push_back(token); // Adds the converted value to the row
            }

            coord_data->push_back(new_row); // Pushes our constructed vector of doubles to the 2D vector
        }
    }


   void write_dataset (int max_x, int max_y, int num_points){

    int rand_x;
    int rand_y;

    srand (time(NULL)); //random seed.

    std::ofstream file_("coords.txt"); //output file .txt

    for (int i = 0; i < num_points; i++){
        rand_x = rand() % *(max_x + 1); //random value ranges from 0 - max_x
        rand_y = rand() % (max_y + 1); //random value ranges from 0 - max_y
        file_ << rand_x << " " << rand_y;
        if (i != num_points - 1)
        {
            file_ << "\n";
        }
    }

    file_.close();

}
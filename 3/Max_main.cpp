
// Libraries.........................................................................................................................

#include"KDTREE.hpp"

// FUNCTION DECLARATION...............................................................................................................

void write_dataset (int max_x, int max_y, int num_points); //  A function to creste random dataset
/* Later we can make this function flexible to produce data points for any numner of dimenstion,
based on the number of input entered by the user. e.g. If three argments are entered the first two
are x and y, and the third one is "num_points". If four argments are entered the first three
are x, y and z, and the forth one is "num_points".The last argument could always be "num_points"
and all previous arguments are max values for flexible number of dimentions (k dimensions)
"k" is the number of dimensions could be determined in this function.
*/


void ReadFile(std::string in_fname, std::vector<std::vector<double>> *const coord_data); //  A function to read from the input text file





//Main File..........................................................................................................................

int main(){

    // Defining variables

    int max_x, max_y, num_points, num_k; //maximum longitude, maximum latitude, number of data points

    std::string in_fname; //input file name

    std::vector<std::vector<double>> coord_data; // A 2-d vector to store coord data points

    std::vector<double>new_ptn_vec;//A vector for the new point we want to test in prediction phase

    std::vector<double>max_dim_vec; //A vector to store maximum values permitted by the user for each dimention

    // Getting input data from user

    // sking for the number of dimensions
    std::cout<<"Please enter the number of dimensions (k) for the k-d tree: "

    std::cin>>num_k;

    // Asking for the maximum vales for each dimention

    std::cout<< "Please enter values for the maximum longitude, maximum latitude and number of data points, repectively and seperated by space:";

    int max_val_dim;

    for (int i = 0 ; i < num_k ; i++){

        cin >> max_val_dim;

        max_dim_vec.push_back (num);

        std::cin>> max_x >> max_y >; // Requesting values for the parameters of "dataset" generator function

    std::cout<< "Please enter number of data points: ";

    std::cin>> num_points;

    // program requesting new point coordinatres (with maximum values for each dimension)
    std::cout<<"Please enter a number, or numbers separated by a space, between zero and "

    for (int i = 0 ; i < max_dim_vec.size() ; i++){

        std::cout<<max_dim_vec[i]<<std::cout<<", ";
    }
    std::cout<< " for the dimentions respectively, to find the closest point to that:"<< std::endl;


    // Usier input for the new point to be predicted
    int num;
    for (int i = 0 ; i < num_k ; i++){
        cin >> num;
        new_ptn_vec.push_back (num);
    }


    // Calling helper functions

    write_dataset (int max_x, int max_y, int num_points);// Making random dataset

    ReadFile(std::string in_fname, std::vector<std::vector<double>> *const coord_data);// Reading data from input text file

    // Making a KDTREE Object and calling corresponding methods

    KDTREE kdt_obj;

    // Constructing the tree-structure using produced coord_data in previous steps

    kdt_obj.construct_tree(coord_data)

    // Searching for the Nearest neighbor (one data point) to the new point

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


   void write_dataset (std::vector<double>max_dim_vec,  int num_points){//Getting the vector containing maximum values for each dimension

    int rand_x;
    int rand_y;

    srand (time(NULL)); //random seed.

    std::ofstream file_("coords.txt"); //output file .txt

    /*//we want to go over rows of points, and also "k" number of coordinates at every row,
        and write every coordinate of every point and a space between them. Then a new line, and the next point */

    for (int i = 0; i < num_points; i++){//for every data point

        std::vector<double>temp_vec;

        for (int j = 0 ; j < max_dim_vec.size() ; j++){

            temp_vec.push_back(rand() % *(max_dim_vec[j] + 1)) ; //random value ranges from 0 - max_x


        for (int k = 0 ; k < temp_vec.size() ; k++){//for every coordinate of a data point

            file_ << temp_vec[k] << " " ; //Then we put the contents of temporary vector to the file

        if (i != num_points - 1)
        {
            file_ << "\n";
        }
        }
    }

    file_.close();

}
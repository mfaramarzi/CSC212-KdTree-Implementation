
#include"tree.hpp"
#include"IO.hpp"


int main(int argc, char** argv)
{ 
    std::vector<int>max_values;

    for (int i = 3 ; i < argc ; i++)
    {
        max_values.push_back(std::stoi(argv[i]));//pushing max values for random data points at each dimension (entered by user)
    }

    IO io_obj( std::stoi(argv[1]) , std::stoi(argv[2]) , max_values); // num_points,  num_k  , max_dim_vec 

    io_obj.write_dataset ();//Writing a random dataset to a file named "datapoints.txt" in the current directory

    io_obj.ReadFile();//Reading "datapoints.txt" to a 2-d vector in KDTree class named "coord_data"

    KDTree tree_obj(io_obj.coord_data);//making kdtree object//I should use coord_data instead of vec_2d everywhere

    tree_obj.populate_tree(io_obj.coord_data);//calling populate_tree method onthe tree object

    tree_obj.write_dot_file();//Somewhere the num_points has conflict with coord_data.size()  

    std::vector<int>new_pnt = {7,3,7};//A newpoint to be inserted to the tree

    tree_obj.insert(new_pnt);//Comment in/out to test if the point could be found in search (next line)
    
    tree_obj.search(new_pnt);//Search new_pnt
}
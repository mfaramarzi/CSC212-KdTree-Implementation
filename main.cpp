#include"tree_test.hpp"
#include"IO.hpp"


int main(){

    // std::vector<std::vector<int> > vec_2d{{6,5,2},{1,8,9}, {7,1,1},{7,8,7},{7,3,6},
    //                                       {2,1,4},{1,4,1},{8,7,3},{6,2,8},{2,8,6},
    //                                       {9,1,4},{2,8,3},{8,1,4},{9,4,1},{7,2,9}};

    IO io_obj( 20 , 5  , {100, 100, 100,100,100}); // num_points,  num_k  , max_dim_vec

    io_obj.write_dataset ();

    io_obj.ReadFile();

    KDTree tree_obj(io_obj.coord_data);//making kdtree object//I should use coord_data instead of vec_2d everywhere

    tree_obj.populate_tree(io_obj.coord_data);//calling populate_tree method onthe tree object

    tree_obj.write_dot_file();

    // std::vector<int>new_pnt = {7,3,7};

    // tree_obj.insert(new_pnt);//Point is added??
    
    // bool test = tree_obj.search(new_pnt);//Search a point

    // std::cout<<test;
   
    


}
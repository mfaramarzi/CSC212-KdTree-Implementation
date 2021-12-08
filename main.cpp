#include"tree_test.hpp"
#include"IO.hpp"


int main(int argc, char** argv)
{ 

    // std::vector<std::vector<int> > vec_2d{{6,5,2},{1,8,9}, {7,1,1},{7,8,7},{7,3,6},
    //                                       {2,1,4},{1,4,1},{8,7,3},{6,2,8},{2,8,6},
    //                                       {9,1,4},{2,8,3},{8,1,4},{9,4,1},{7,2,9}};

    // std::vector<std::vector<int> > vec_2d {{75, 42, 29, 59, 43}, {99, 13, 12, 99, 56 }, {37, 86, 54, 5, 18}, {15, 79, 59, 40, 85  }, {90, 37, 79, 73, 78},
    // {65, 74, 47, 67, 39}, {61, 7, 81, 90, 32 }, {24, 54, 45, 2, 52, }, {0, 6, 4, 54, 78, }, {22, 35, 56, 47, 41},
    // {41, 36, 79, 86, 75, }, {22, 50, 14, 69, 83}, {54, 29, 57, 34, 85}, {89, 24, 4, 34, 27, }, {23, 34, 33, 27, 55},
    // {77, 15, 56, 33, 28}, {98, 40, 65, 42, 25, }, {39, 64, 41, 20, 99}, {90, 74, 95, 46, 7}
    // };
    std::vector<int>temp_vec;

    for (int i = 3 ; i < argc ; i++){

        temp_vec.push_back(std::stoi(argv[i]));

    }

    IO io_obj( std::stoi(argv[1]) , std::stoi(argv[2]) , temp_vec); // num_points,  num_k  , max_dim_vec  //  31 , 5  , {1000, 1000, 1000, 1000, 1000} // std::stoi(argv[1]) , std::stoi(argv[2]) , temp_vec

    io_obj.write_dataset ();

    io_obj.ReadFile();

    KDTree tree_obj(io_obj.coord_data);//making kdtree object//I should use coord_data instead of vec_2d everywhere

    tree_obj.populate_tree(io_obj.coord_data);//calling populate_tree method onthe tree object

    // std::vector<std::vector<int>>inorder_vec;
    
    // tree_obj.inOrder(tree_obj.root);//

  

    tree_obj.write_dot_file();//Somewhere the num_points has conflict with coord_data.size()   ?????????????? Only when num_points = 15, there is no conflict

    // std::vector<int>new_pnt = {7,3,7};

    // tree_obj.insert(new_pnt);//Point is added??
    
    // bool test = tree_obj.search(new_pnt);//Search a point

    // std::cout<<test;
   




}
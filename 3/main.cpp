#include"tree_test.hpp"


int main(){

    std::vector<std::vector<int> > vec_2d{{6,5,2},{1,8,9}, {7,1,1},{7,8,7},{7,3,6},
                                          {2,1,4},{1,4,1},{8,7,3},{6,2,8},{2,8,6},
                                          {9,1,4},{2,8,3},{8,1,4},{9,4,1},{7,2,9}};

// std::cout<<vec_2d.size();
    KDTree tree_obj(vec_2d);//making kdtree object

    tree_obj.populate_tree(vec_2d);//calling populate_tree method onthe tree object

    // std::cout<<"mmmmmm";

    // tree_obj.write_dot_file();

    std::vector<int>new_pnt = {6,5,2};
    
    bool test = tree_obj.search(new_pnt);//Search a point

    // std::cout<<test;
   
    // tree_obj.insert(new_pnt);//Point is added??


}
#include"tree_test.hpp"


int main(){

    std::vector<std::vector<int> > vec_2d{{3, 5, 1},
                                {4, 8, 6},
                                {7, 2, 9}};
    KDTree tree_obj(vec_2d);//making kdtree object

    tree_obj.populate_tree(vec_2d, tree_obj.depth);//calling populate_tree method onthe tree object
    // tree_obj.populate_tree(std::vector<std::vector<int>> vec_2d , int depth )
}
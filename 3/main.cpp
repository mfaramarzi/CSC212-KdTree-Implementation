#include"tree_test.hpp"


int main(){

    std::vector<std::vector<int> > vec_2d{{3, 5, 1},
                                {4, 8, 6},
                                {7, 2, 9}};
    KDTree tree_obj(vec_2d);//making kdtree object

    tree_obj.populate_tree(vec_2d, tree_obj.depth);//calling populate_tree method onthe tree object

    // std::vector<int>new_pnt = {4, 8, 6};
    
    // tree_obj.search(new_pnt);//Can I remove the depth fromt he arguments in the insert func?????
    // I can make root a private object in the KDTree class, and pass it to the body of search method directly, instead of have a argument for that in search method,
}
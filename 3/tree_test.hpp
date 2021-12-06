#include <iostream>
#include <vector>
#include <algorithm>    // std::sort


class Node
{
    private:

        std::vector<int> data; //takes in a vector with k number of data.
        Node* left;//a pointer named left,  pointing to an object type Node
        Node* right;//a pointer named right,  pointing to an object type Node

        friend class KDTree;

    public:

        Node(std::vector<int> &data);//node class constructor
        ~Node();//node class deconstructor

        void getData();// Function ro read k values of a node

        

};






//KDTree is the class for the tree itself
class KDTree{

    private:

        Node* root;//A pointer to the root node (private)

        int k; //number of dimensions

        
        // 

        std::vector<std::vector<int>> vec_2d; //2-d vector containing bunch of k-dim points.

        static bool sortcol( const std::vector<int>& v1, const std::vector<int>& v2 );
        // Using objects???
        // wrape array and vec in a struct???
        // 

        bool arePointsSame(std::vector<int> point1, std::vector<int> point2);

        inline static int dim_each_rec;
        // inline????

    public:

        int depth; //value to store the depth, starting from zero, ending the depth of last leaf.

        KDTree(std::vector<std::vector<int>> vec_2d);//Class KDTree constructor. Will result in a balanced KDTree object populated by the nodes containing K dimensional points from 2-d vector

        ~KDTree();

        Node* populate_tree(std::vector<std::vector<int>> vec_2d , int depth );

        // insert Method
        Node *insert(Node *root, std::vector<int> new_pnt, int depth);

        // Search method
        bool search(Node *root, std::vector<int> new_pnt, int depth);
        
      
        // Delete Method??????????????

        // nearest neighbor method??????????????????
        

};













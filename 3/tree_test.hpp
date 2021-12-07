#include <iostream>
#include <vector>
#include <algorithm>   
#include<stack> 
#include <fstream>

// ------------------------------------------------------------------------------------------------------------------------------------
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

// ------------------------------------------------------------------------------------------------------------------------------------
class KDTree{

    private:

        

        int k; //number of dimensions

        std::vector<std::vector<int>> vec_2d; //2-d vector containing bunch of k-dim points.

        static bool sortcol( const std::vector<int>& v1, const std::vector<int>& v2 ); 

        bool arePointsSame(std::vector<int> point1, std::vector<int> point2);

        inline static int dim_each_rec;

        Node* populate_tree(std::vector<std::vector<int>> vec_2d , int depth );//Tree generator

         bool search(Node *root, std::vector<int> new_pnt, int depth);//Private search method

         Node *insert(Node *root, std::vector<int> new_pnt, int depth);// Private insert method

         std::vector<std::vector<int>> dot_file_conn;

        //  ------------------------------------------------------------------------

    public:

        int depth; //value to store the depth, starting from zero, ending the depth of last leaf.

        Node* root;//A pointer to the root node (private)

        KDTree(std::vector<std::vector<int>> vec_2d);//Class KDTree constructor

        ~KDTree();//Deconstructor

        void populate_tree(std::vector<std::vector<int>> vec_2d );
        
        void insert( std::vector<int> new_pnt);// Public insert Method
        
        bool search( std::vector<int> new_pnt);// Public Search method
        
        // Delete Method??????????????

        // nearest neighbor method??????????????????
        
        std::vector<std::vector<int>> inOrder(Node* root);//inorder traverse

        void write_dot_file();
};












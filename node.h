#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <vector>



class Node
{
    private:

        std::vector<int> data; //takes in a vector with k number of data.
        Node* left;
        Node* right;


    public:

        Node(std::vector<int> data);
        ~Node();

        void getData();




};


#endif
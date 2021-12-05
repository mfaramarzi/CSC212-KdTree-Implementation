#include "node.h"

Node::Node(std::vector<int> data)
{
    for (int i = 0; i < data.size(); i++)
    {
        this->data.push_back(data[i]); //
        std::cout << "i is " << i << "\n";
    }

    this->left = nullptr;
    this->right = nullptr;
}

Node::~Node()
{

}

void Node::getData()
{
    for (int i = 0; i < this->data.size(); i++)
    {
        std::cout << this->data[i] << "\n"; //
    }
}







#include "tree_test.hpp"

// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Node::Node(std::vector<int> &data)//node constructor getting 1-d vector of points
{
    for (int i = 0; i < data.size(); i++)//iterate over all values of a data point
    {
        this->data.push_back(data[i]); //writing all values of a data point to the node

        // std::cout << "i is " << data[i] << "\n";//printing the axis (dimension) 0,1,2...k //Why do we need to print them.for testing???????
    }

    this->left = nullptr;//Assigning two null pointer to the new node's pointer named left

    this->right = nullptr;
}

Node::~Node()
{

}

void Node::getData()//function to read k values of a data point from a node
{
    for (int i = 0; i < this->data.size(); i++)
    {
        std::cout << this->data[i] << "\n"; //
    }
}


// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Tree Class Functions


// Driver function to sort the 2D vector on basis of a particular column
// return
//Getting three parameters,two vectors and the searching dimension
bool KDTree::sortcol( const std::vector<int>& v1, const std::vector<int>& v2) {

 return v1[dim_each_rec] < v2[dim_each_rec];

}

// ---------------------------------------------------------------

// A utility method to determine if two Points are same
// in K Dimensional space
bool KDTree::arePointsSame(std::vector<int> point1, std::vector<int> point2){
    // Compare individual pointinate values
    for (int i = 0; i < k; ++i)
        if (point1[i] != point2[i])
            return false;
  
    return true;
}

// ---------------------------------------------------------------

KDTree::KDTree(std::vector<std::vector<int>> vec_2d){ //KDTree constructor

    depth = 0; //Initiate depth as zero for the root node

    k = vec_2d[0].size();  //FINDING THE NUMBER OF DIMENSIONS FROM THE 2-D VECTOR OF POINTS
}

// ---------------------------------------------------------------

KDTree::~KDTree(){//deconstructor of KDTree type object

}
// ---------------------------------------------------------------

Node* KDTree::populate_tree(std::vector<std::vector<int>> vec_2d , int depth ){// Function to CONSTRUCT the KD tree

    //base case, when there is no more datapoint in the vector
    if(vec_2d.size() == 0 ){
        //since you are checking for vector size as a base case you need to delete the vector entries.
        return nullptr;
    }


// Finding the dimension of current level in the tree

    int dimension = depth % k;

    KDTree::dim_each_rec = dimension;


// Sorting the 2-d vector by considering the current dimension axis

     std::sort(vec_2d.begin(), vec_2d.end(),sortcol);//Using sortcol function defined above


// Finding the median of tree/subtree

    int Med_point_idx = vec_2d.size()/2;//selecting the median point



// Creating node using the median point
// calling node constructor and inputting the median as the parameter




    Node root_node(vec_2d[Med_point_idx]);//how is it connected to its parent node??I should call node class here

std::vector<std::vector<int>>vec_2d_left;

std::vector<std::vector<int>>vec_2d_right;

vec_2d_left = std::vector<std::vector<int>>(vec_2d.begin(), vec_2d.begin()+ Med_point_idx); //using std::vector's copy constructor

vec_2d_right = std::vector<std::vector<int>>( vec_2d.begin()+ Med_point_idx + 1 , vec_2d.end()); //using std::vector's copy constructor

// Recursive calls on the left node and right node

// /I want the constructed tree in this level, points to the left node, which is a recursive funct to tree constructor
    root_node.left = populate_tree (vec_2d_left , depth + 1);//Check the first last
    //popule

    root_node.right = populate_tree (vec_2d_right, depth + 1);

}

// ---------------------------------------------------------

// Inserts a new node and returns root of modified tree
// The parameter depth is used to decide axis of comparison
Node* KDTree::insert(Node *root, std::vector<int> new_pnt, int depth){//Private insert method
    // Tree is empty?
    if (root == NULL)
       return new Node(new_pnt);
  
    // Calculate current dimension (cd) of comparison
    unsigned cd = depth % k;
  
    // Compare the new point with root on current dimension 'cd'
    // and decide the left or right subtree
    if (new_pnt[cd] < (root->data[cd]))//if the value of current axis for the new point is less than corresponding value for the current node (root node)

        root->left  = insert(root->left, new_pnt, depth + 1);
    else
        root->right = insert(root->right, new_pnt, depth + 1);
  
    return root;
}
// ----------------------------------------------------------

// Function to insert a new point with given point in
// KD Tree and return new root. It mainly uses above recursive
// function "insertRec()"
Node* KDTree::insert( std::vector<int> new_pnt)//Public insert function//removed
{
    return insert(root, new_pnt, 0);
}
// -----------------------------------------------------------

// Searches a Point represented by "point[]" in the K D tree.
// The parameter depth is used to determine current axis.
bool KDTree::search(Node *root, std::vector<int> new_pnt, int depth ){//Private search function
    // Base cases
    if (root == NULL)
        return false;
    if (arePointsSame(new_pnt, root->data))//arguments should be the searching 1-d vec and the node's (root) vec//checking if both points have same values
        return true;
  
    // Current dimension is computed using current depth and total
    // dimensions (k)
    unsigned cd = depth % k;
  
    // Compare point with root with respect to cd (Current dimension)
    if (new_pnt[cd] < root->data[cd])//if the value of checking dimension of new point at specific level is less than checking root (node)

        return search(root->left, new_pnt, depth + 1);//Then search in the left subtree
  
    return search(root->right, new_pnt, depth + 1);//otherwise (or later recusively) check the right subtree
}
  
// -------------------------------------------------------------

    // Searches a Point in the K D tree. It mainly uses
    // searchRec()
    bool KDTree::search( std::vector<int> new_pnt)//Public search func// remioved Node *root,
    {
        // Pass current depth as 0
        return search(root, new_pnt, 0);
    }
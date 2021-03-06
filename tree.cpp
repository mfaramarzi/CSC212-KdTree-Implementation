
#include "tree.hpp"

// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Node::Node(std::vector<int> &data)//node constructor getting 1-d vector of points
{
    for (int i = 0; i < data.size(); i++)//iterate over all values of a data point
    {
        this->data.push_back(data[i]); //writing all values of a data point to the node
    }
    this->left = nullptr;//Assigning two null pointer to the new node's pointer named left

    this->right = nullptr;
}

// --------------------------------------------

Node::~Node(){}

// -----------------------------------------
void Node::getData()//function to read k values of a data point from a node
{
    for (int i = 0; i < this->data.size(); i++)
    {
        std::cout << this->data[i] << "\n"; //
    }
}

// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// Driver function to sort the 2D vector on basis of a particular column
bool KDTree::sortcol( const std::vector<int>& v1, const std::vector<int>& v2) 
{
 return v1[dim_each_rec] < v2[dim_each_rec];
}

// ---------------------------------------------------------------

bool KDTree::arePointsSame(std::vector<int> point1, std::vector<int> point2)// A utility method to determine if two Points are same
{   
    for (int i = 0; i < k; ++i)
        {
        std::cout<<point1[i]<<" "<<point2[i]<<std::endl;

        if (point1[i] != point2[i])
            {
            return false;
            }
        }
    std::cout<<"Point Found"<<std::endl;

    return true;
}

// ---------------------------------------------------------------

KDTree::KDTree(std::vector<std::vector<int>> coord_data)//KDTree constructor
{ 
    root = nullptr;

    depth = 0; //Initiate depth as zero for the root node

    k = coord_data[0].size();  //FINDING THE NUMBER OF DIMENSIONS FROM THE 2-D VECTOR OF POINTS
}

// ---------------------------------------------------------------

KDTree::~KDTree(){} //deconstructor of KDTree type object
// ---------------------------------------------------------------

Node* KDTree::populate_tree(std::vector<std::vector<int>> coord_data , int depth )// Function to CONSTRUCT the KD tree
{
    if(coord_data.size() == 0 )//base case, when there is no more datapoint in the vector
    {
        return nullptr;
    }
    int dimension = depth % k;// Finding the dimension of current level in the tree

    KDTree::dim_each_rec = dimension;

    std::sort(coord_data.begin(), coord_data.end(),sortcol);//Using sortcol function defined above// Sorting the 2-d vector by considering the current dimension axis

    int Med_point_idx = coord_data.size()/2;//selecting the median point

    Node* root_node = new Node (coord_data[Med_point_idx]);//how is it connected to its parent node??I should call node class here

    std::vector<std::vector<int>>coord_data_left;

    std::vector<std::vector<int>>coord_data_right;

    coord_data_left = std::vector<std::vector<int>>(coord_data.begin(), coord_data.begin()+ Med_point_idx); //using std::vector's copy constructor


    if(coord_data.size()> 1)
    {
        coord_data_right = std::vector<std::vector<int>>( coord_data.begin()+ Med_point_idx + 1 , coord_data.end()); //using std::vector's copy constructor
    }
    root_node->left = populate_tree (coord_data_left , depth + 1);//Check the first last

    root_node->right = populate_tree (coord_data_right, depth + 1);
  
    return root_node;
}
// --------------------------------------------------------

    void KDTree::populate_tree(std::vector<std::vector<int>> coord_data )
    {
        this->root = populate_tree (coord_data , this->depth);

        inOrder(this->root);
    }

// ---------------------------------------------------------

Node* KDTree::insert(Node *root, std::vector<int> new_pnt, int depth)//Private insert method
{
    if (root == nullptr) // Tree is empty?
    {
       return new Node(new_pnt);
    }
    unsigned cd = depth % k;// Calculate current dimension (cd) of comparison
  
    if (new_pnt[cd] < (root->data[cd]))// Compare the new point with root on current dimension 'cd'and decide the left or right subtree. if the value of current axis for the new point is less than corresponding value for the current node (root node)
    {
        root->left  = insert(root->left, new_pnt, depth + 1);
    }
    else
    {
        root->right = insert(root->right, new_pnt, depth + 1);
    }
    return root;
}

// ----------------------------------------------------------

void KDTree::insert( std::vector<int> new_pnt)//Public insert function 
{
    root = insert(root , new_pnt, 0);
}
// -----------------------------------------------------------

bool KDTree::search(Node *root, std::vector<int> new_pnt, int depth )//Private search function
{
    if (root == nullptr)// Base cases
    {
        std::cout<<"point not found"<<std::endl;

        return false;
    }

    if (arePointsSame(new_pnt, root->data))//arguments should be the searching 1-d vec and the node's (root) vec//checking if both points have same values
        {
        return true;
        }
    unsigned cd = depth % k;
  
    
    if (new_pnt[cd] < root->data[cd])// Compare point with root with respect to cd (Current dimension). if the value of checking dimension of new point at specific level is less than checking root (node)
    {
        return search(root->left, new_pnt, depth + 1);//Then search in the left subtree
    }
    return search(root->right, new_pnt, depth + 1);//otherwise (or later recusively) check the right subtree
}
  
// -------------------------------------------------------------

    bool KDTree::search( std::vector<int> new_pnt)//Public search func// remioved Node *root,
    {
            return search(root, new_pnt, 0);  // Pass current depth as 0
    }
    // -------------------------------------------------------
  
void KDTree::inOrder(Node* root)//Recursive function to find inorder sequence ofnodes in the tree. Later we make connections between nodes (second version)  
{
    if(!root)
    {
        return;
    }
    this->inOrder(root->left);

    if (root->left != nullptr)
    {
        dot_file_conn.push_back(std::make_pair(root->data,root->left->data));
    }
    if(root->right != nullptr)
    {
        dot_file_conn.push_back(std::make_pair(root->data,root->right->data));
    }
    this->inOrder(root->right);

    return;
}

    // -------------------------------------------------------------------------------

    void KDTree::write_dot_file() //Using inordered datapoints to write conncetions between nodes to the "dot_file.txt"
    {
        std::ofstream file_("dot_file.txt"); //output file .txt

        for (int i = 0; i < dot_file_conn.size(); i++)//for every data point
        {
            for(int j = 0 ; j<dot_file_conn[i].first.size() ; j++)//it is  0,1,2
            {
                file_ << "_" << dot_file_conn[i].first[j];
            }
           file_  <<" -> ";
           
           for(int j = 0 ; j < dot_file_conn[i].second.size() ; j++)
           {
               file_ <<"_" << dot_file_conn[i].second[j] ;     
            }
            file_ <<"\n" ;
        }
    file_.close(); 
    }

// -----------------------------------------------------------------------------------
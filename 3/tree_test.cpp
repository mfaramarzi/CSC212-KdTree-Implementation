#include "tree_test.hpp"

// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Node::Node(std::vector<int> &data)//node constructor getting 1-d vector of points
{
    for (int i = 0; i < data.size(); i++)//iterate over all values of a data point
    {
        this->data.push_back(data[i]); //writing all values of a data point to the node

        // std::cout << data[i] <<"\n";//printing the axis (dimension) 0,1,2...k //Why do we need to print them.for testing???????
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
    for (int i = 0; i < k; ++i){
        std::cout<<point1[i]<<" "<<point2[i]<<std::endl;
        if (point1[i] != point2[i])
            return false;}
    std::cout<<"Point Found"<<std::endl;
    return true;
}

// ---------------------------------------------------------------

KDTree::KDTree(std::vector<std::vector<int>> vec_2d){ //KDTree constructor

    // this->vec_2d = std::vector<std::vector<int>> vec_2d;
    // this->vec_2d.assign(vec_2d.begin(), vec_2d.end());
    // this->vec_2d = vec_2d;

    this->vec_2d = std::vector<std::vector<int>>(vec_2d.begin(), vec_2d.end());

    root = nullptr;

    depth = 0; //Initiate depth as zero for the root node

    k = vec_2d[0].size();  //FINDING THE NUMBER OF DIMENSIONS FROM THE 2-D VECTOR OF POINTS

    // std::cout<<k;
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

    // std::cout<<dim_each_rec;


// Sorting the 2-d vector by considering the current dimension axis

     std::sort(vec_2d.begin(), vec_2d.end(),sortcol);//Using sortcol function defined above

// std::cout<<vec_2d[0][0];
// Finding the median of tree/subtree

    int Med_point_idx = vec_2d.size()/2;//selecting the median point
// std::cout<<vec_2d.size();
// std::cout<<Med_point_idx;

// Creating node using the median point
// calling node constructor and inputting the median as the parameter


    Node* root_node = new Node (vec_2d[Med_point_idx]);//how is it connected to its parent node??I should call node class here

    // std::cout<<root_node;

    /*file<<
    //printing three elements of a k=3 point in pranthesis seperated by comma

    for (int i = 0; i < vec_2d.size() ; i++)
        std::std::cout<<'_'<<vec_2d[Med_point_idx][i] <<" -> "<<;

    
    */

    std::vector<std::vector<int>>vec_2d_left;

    std::vector<std::vector<int>>vec_2d_right;

    // std::cout<<Med_point_idx;

    vec_2d_left = std::vector<std::vector<int>>(vec_2d.begin(), vec_2d.begin()+ Med_point_idx); //using std::vector's copy constructor

// std::cout<<vec_2d_left[0][0];

    if(vec_2d.size()> 1){
        vec_2d_right = std::vector<std::vector<int>>( vec_2d.begin()+ Med_point_idx + 1 , vec_2d.end()); //using std::vector's copy constructor

    }

    // std::cout<<vec_2d_right[0][0];

// Recursive calls on the left node and right node

// /I want the constructed tree in this level, points to the left node, which is a recursive funct to tree constructor
    root_node->left = populate_tree (vec_2d_left , depth + 1);//Check the first last
    //popule

    root_node->right = populate_tree (vec_2d_right, depth + 1);

    // dot_file_conn.push_back(vec_2d[Med_point_idx]);//It is after each left and right recursions.

    // dot_file_conn.push_back(root_node->left->data );//root node is the same as median point above? 

    // dot_file_conn.push_back(vec_2d[Med_point_idx]);//It is after each left and right recursions. Should I have it pushed again here??????????????????????????!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    // dot_file_conn.push_back(root_node->right->data);
    // Then in the dot file function I can make a line from every two vectors in sequence (med and left and med and right)

    return root_node;
}
// --------------------------------------------------------

    void KDTree::populate_tree(std::vector<std::vector<int>> vec_2d ){

        this->root = populate_tree (vec_2d , this->depth);
    }

// ---------------------------------------------------------

// Inserts a new node and returns root of modified tree
// The parameter depth is used to decide axis of comparison
Node* KDTree::insert(Node *root, std::vector<int> new_pnt, int depth){//Private insert method
    // Tree is empty?
    if (root == nullptr)
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
void KDTree::insert( std::vector<int> new_pnt)//Public insert function//removed
    
{
    root = insert(root , new_pnt, 0);
}
// -----------------------------------------------------------

// Searches a Point represented by "point[]" in the K D tree.
// The parameter depth is used to determine current axis.
bool KDTree::search(Node *root, std::vector<int> new_pnt, int depth ){//Private search function
    // Base cases
    if (root == nullptr){
        std::cout<<"point not found"<<std::endl;
        return false;}
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
    // -------------------------------------------------------
    // Traverse in order
    std::vector<std::vector<int>> KDTree::inOrder(Node* root) {
        std::vector<std::vector<int>> v;
        std::stack<Node*> s;
        
        if (root==NULL)
            return v;
            
        Node* node = root;
        
        while (1) {
            if (node != NULL) {
                s.push(node);
                node = node->left;
            }
            else {
                if (s.empty())
                    break;
                    
                node = s.top();
                s.pop();
                v.push_back(node->data);
                
                node = node->right;
            }
    }
    }

    // Making .dot file 

    void KDTree::write_dot_file(){

        std::ofstream file_("dot_file.txt"); //output file .txt

        for (int i = 0; i < dot_file_conn.size() - 1; i++){//for every data point

            for(int j = 0 ; j<dot_file_conn[i].size() ; j++){

                file_ << "_" << dot_file_conn[i][j] ;
            }

           file_  <<" -> ";
           
           for(int j = 0 ; j<dot_file_conn[i].size() ; j++){

               file_ <<"_" << dot_file_conn[i + 1][j] ;     
            }

            file_ <<"\n" ;
        }

    file_.close(); 
    }
// I should find the first point before each point with higher k and connect those two points
// push what they point to

// It determnes the connections in dot_file_conn????
// std::vector<std::pair<std::vector<int> , <std::vector<int>>>dot_file_conn; //I need source and destination??? pair of two vectors, 

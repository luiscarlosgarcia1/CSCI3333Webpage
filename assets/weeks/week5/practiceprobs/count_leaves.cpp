// ## Count leaves on tree
//
// For the following question, assume binary trees consist of nodes from
// the following class:

class node {
public:
    double data;
    node* left;
    node* right;
    node(double x) { data = x; left = nullptr; right = nullptr; }
};

// Function to count the leaf nodes in a binary tree
int countLeaves(node* root) 
{
    if (!root) {return 0;}
    if (!root->left && !root->right) {return 1;}

    return countLeaves(root->left) + countLeaves(root->right);
}

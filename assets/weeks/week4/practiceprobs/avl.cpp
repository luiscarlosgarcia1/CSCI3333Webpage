// Suppose the following AVL Tree node class is given:

class AVLNode {
public:
    int data;
    AVLNode* left;
    AVLNode* right;
    int height;
};

// An empty subtree has height 0.
int getHeight(AVLNode* node) {
    if (node == nullptr)
        return 0;

    return node->height;
}

// Recalculate height after changing one of a node's children.
void updateHeight(AVLNode* node) {
    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);

    if (leftHeight > rightHeight)
        node->height = leftHeight + 1;
    else
        node->height = rightHeight + 1;
}

// Implement the following. (You may assume helper functions such as getHeight() are allowed.)

// 1. Function to compute and return the balance factor of a node (check difference
//    between left and right subtree):
//    int getBalance(AVLNode* node)
int getBalance(AVLNode* node) {
    if (node == nullptr)
        return 0;

    return getHeight(node->left) - getHeight(node->right);
}

// 2. Right rotation function and return root of subtree:
//    AVLNode* rightRotate(AVLNode* p)
AVLNode* rightRotate(AVLNode* p) {
    AVLNode* A = p;        // The unbalanced node.
    AVLNode* B = A->left;  // B moves up to become the new root.
    AVLNode* C = B->right; // C is moved between A and B.

    B->right = A;
    A->left = C;

    // A is now below B, so update A first.
    updateHeight(A);
    updateHeight(B);

    return B;
}

// 3. Left rotation function and return root of subtree:
//    AVLNode* leftRotate(AVLNode* p)
AVLNode* leftRotate(AVLNode* p) {
    AVLNode* A = p;         // The unbalanced node.
    AVLNode* B = A->right;  // B moves up to become the new root.
    AVLNode* C = B->left;   // C is moved between A and B.

    B->left = A;
    A->right = C;

    // A is now below B, so update A first.
    updateHeight(A);
    updateHeight(B);

    return B;
}

// 4. BONUS: Insert() function (inserts a value into the AVL Tree and restores
//    balance using rotations when necessary)
AVLNode* insert(AVLNode* root, int value) {
    // First, do a normal binary-search-tree insertion.
    if (root == nullptr)
        return new AVLNode{value, nullptr, nullptr, 1};

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    else // This version ignores duplicate values.
        return root;


    // Update height
    updateHeight(root);
    int balance = getBalance(root);


    // Left-Left: left side too tall; value added left of left child.
    // Fix: rotate right.
    if (balance > 1 && value < root->left->data) {
        return rightRotate(root);
    }

    // Right-Right: right side too tall; value added right of right child.
    // Fix: rotate left.
    if (balance < -1 && value > root->right->data) {
        return leftRotate(root);
    }

    // Left-Right: left side too tall; value added right of left child.
    // Fix zig-zag: left rotate child, then right rotate root.
    if (balance > 1 && value > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right-Left: right side too tall; value added left of right child.
    // Fix zig-zag: right rotate child, then left rotate root.
    if (balance < -1 && value < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

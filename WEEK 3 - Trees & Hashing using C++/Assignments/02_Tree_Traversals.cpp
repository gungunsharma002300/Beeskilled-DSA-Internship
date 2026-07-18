#include <iostream>
using namespace std;

/*
 * Task 2: Write recursive functions for tree traversals.
 * Also covers Practice Question 3: Perform inorder, preorder, postorder traversals.
 *
 * Builds a BST and prints it using all three traversal methods.
 */

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node* insert(Node* root, int value) {
    if (root == nullptr) return createNode(value);
    if (value < root->data) root->left = insert(root->left, value);
    else if (value > root->data) root->right = insert(root->right, value);
    return root;
}

// Left -> Root -> Right
void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Root -> Left -> Right
void preorder(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Left -> Right -> Root
void postorder(Node* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = nullptr;
    int n;

    cout << "=== BST Tree Traversals ===" << endl;
    cout << "How many values do you want to insert? ";
    cin >> n;

    cout << "Enter " << n << " integer values:" << endl;
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        root = insert(root, value);
    }

    cout << "Inorder traversal   : ";
    inorder(root);
    cout << endl;

    cout << "Preorder traversal  : ";
    preorder(root);
    cout << endl;

    cout << "Postorder traversal : ";
    postorder(root);
    cout << endl;

    return 0;
}

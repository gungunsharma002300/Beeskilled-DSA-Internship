#include <iostream>
using namespace std;

/*
 * Practice Question 2: Build a Binary Search Tree (BST) with insert & display.
 * Practice Question 4: Find minimum and maximum elements in a BST.
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

void display(Node* root) {
    // inorder display = sorted order for a BST
    if (root == nullptr) return;
    display(root->left);
    cout << root->data << " ";
    display(root->right);
}

// The minimum value in a BST is always the leftmost node
int findMin(Node* root) {
    if (root == nullptr) {
        cout << "Tree is empty!" << endl;
        return -1;
    }
    while (root->left != nullptr) {
        root = root->left;
    }
    return root->data;
}

// The maximum value in a BST is always the rightmost node
int findMax(Node* root) {
    if (root == nullptr) {
        cout << "Tree is empty!" << endl;
        return -1;
    }
    while (root->right != nullptr) {
        root = root->right;
    }
    return root->data;
}

int main() {
    Node* root = nullptr;
    int n;

    cout << "=== BST - Insert, Display, Min & Max ===" << endl;
    cout << "How many values do you want to insert? ";
    cin >> n;

    cout << "Enter " << n << " integer values:" << endl;
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        root = insert(root, value);
    }

    cout << "BST (sorted/inorder display): ";
    display(root);
    cout << endl;

    cout << "Minimum value in BST: " << findMin(root) << endl;
    cout << "Maximum value in BST: " << findMax(root) << endl;

    return 0;
}

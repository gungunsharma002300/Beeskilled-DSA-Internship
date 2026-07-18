#include <iostream>
using namespace std;

/*
 * Task 1: Build a Binary Search Tree and search for a value.
 *
 * Lets the user insert numbers into a Binary Search Tree (BST)
 * and then search for a value inside it.
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
    if (root == nullptr) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    // duplicate values are ignored
    return root;
}

bool search(Node* root, int value) {
    if (root == nullptr) {
        return false;
    }
    if (root->data == value) {
        return true;
    }
    if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

// Simple inorder display to confirm the tree was built correctly
void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;
    int n;

    cout << "=== Binary Search Tree - Build & Search ===" << endl;
    cout << "How many values do you want to insert? ";
    cin >> n;

    cout << "Enter " << n << " integer values:" << endl;
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        root = insert(root, value);
    }

    cout << "BST (inorder / sorted order): ";
    inorder(root);
    cout << endl;

    int key;
    cout << "Enter a value to search for: ";
    cin >> key;

    if (search(root, key)) {
        cout << key << " found in the BST." << endl;
    } else {
        cout << key << " NOT found in the BST." << endl;
    }

    return 0;
}

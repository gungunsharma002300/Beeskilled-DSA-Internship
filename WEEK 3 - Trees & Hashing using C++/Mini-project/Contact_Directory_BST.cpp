#include <iostream>
#include <string>
using namespace std;

/*
 * Mini Project: Contact Directory (BST Based)
 *
 * - Insert, Search, Delete contacts.
 * - Display alphabetically using inorder().
 *
 * Each contact has a name (used as the BST key, so contacts stay
 * sorted alphabetically) and a phone number.
 */

struct Contact {
    string name;
    string phone;
    Contact* left;
    Contact* right;
};

Contact* createContact(const string& name, const string& phone) {
    Contact* newContact = new Contact();
    newContact->name = name;
    newContact->phone = phone;
    newContact->left = nullptr;
    newContact->right = nullptr;
    return newContact;
}

// Insert a new contact (BST ordered by name)
Contact* insert(Contact* root, const string& name, const string& phone) {
    if (root == nullptr) {
        return createContact(name, phone);
    }
    if (name < root->name) {
        root->left = insert(root->left, name, phone);
    } else if (name > root->name) {
        root->right = insert(root->right, name, phone);
    } else {
        // contact already exists, update phone number
        root->phone = phone;
        cout << "Contact '" << name << "' already existed. Phone number updated." << endl;
    }
    return root;
}

// Search a contact by name
Contact* search(Contact* root, const string& name) {
    if (root == nullptr || root->name == name) {
        return root;
    }
    if (name < root->name) {
        return search(root->left, name);
    } else {
        return search(root->right, name);
    }
}

// Find the node with the smallest name in a subtree (used by delete)
Contact* findMin(Contact* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

// Delete a contact by name
Contact* deleteContact(Contact* root, const string& name) {
    if (root == nullptr) {
        return root;
    }

    if (name < root->name) {
        root->left = deleteContact(root->left, name);
    } else if (name > root->name) {
        root->right = deleteContact(root->right, name);
    } else {
        // found the contact to delete

        // Case 1: no children
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }
        // Case 2: one child
        else if (root->left == nullptr) {
            Contact* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Contact* temp = root->left;
            delete root;
            return temp;
        }
        // Case 3: two children
        else {
            Contact* successor = findMin(root->right);
            root->name = successor->name;
            root->phone = successor->phone;
            root->right = deleteContact(root->right, successor->name);
        }
    }
    return root;
}

// Display contacts alphabetically (inorder traversal)
void inorderDisplay(Contact* root) {
    if (root == nullptr) return;
    inorderDisplay(root->left);
    cout << "Name: " << root->name << "\tPhone: " << root->phone << endl;
    inorderDisplay(root->right);
}

void printMenu() {
    cout << "\n===== Contact Directory (BST Based) =====" << endl;
    cout << "1. Insert Contact" << endl;
    cout << "2. Search Contact" << endl;
    cout << "3. Delete Contact" << endl;
    cout << "4. Display All Contacts (Alphabetical)" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    Contact* root = nullptr;
    int choice;

    do {
        printMenu();
        cin >> choice;
        cin.ignore(); // consume leftover newline

        if (choice == 1) {
            string name, phone;
            cout << "Enter contact name: ";
            getline(cin, name);
            cout << "Enter phone number: ";
            getline(cin, phone);
            root = insert(root, name, phone);
            cout << "Contact inserted successfully." << endl;

        } else if (choice == 2) {
            string name;
            cout << "Enter name to search: ";
            getline(cin, name);
            Contact* result = search(root, name);
            if (result != nullptr) {
                cout << "Found -> Name: " << result->name << ", Phone: " << result->phone << endl;
            } else {
                cout << "Contact '" << name << "' not found." << endl;
            }

        } else if (choice == 3) {
            string name;
            cout << "Enter name to delete: ";
            getline(cin, name);
            if (search(root, name) != nullptr) {
                root = deleteContact(root, name);
                cout << "Contact '" << name << "' deleted successfully." << endl;
            } else {
                cout << "Contact '" << name << "' not found." << endl;
            }

        } else if (choice == 4) {
            cout << "\n---- Contacts (Alphabetical Order) ----" << endl;
            if (root == nullptr) {
                cout << "No contacts saved yet." << endl;
            } else {
                inorderDisplay(root);
            }

        } else if (choice == 5) {
            cout << "Exiting Contact Directory. Goodbye!" << endl;

        } else {
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 5);

    return 0;
}

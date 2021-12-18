#include <iostream>

using namespace std;

struct Treenode {
    int value;
    struct Treenode *left;
    struct Treenode *right;
};

Treenode *Tree;
bool IsEmpty = true;

void console();

struct Treenode * CreateNode(int value, Treenode *t_ptr);
void DeleteNode(int value, Treenode *parent_ptr, Treenode *t_ptr, bool IsRight);

void Printing_infix(Treenode *t_ptr);
void Printing_prefix(Treenode *t_ptr);
void Printing_postfix(Treenode *t_ptr);

void Search(int value, Treenode *t_ptr);

int main() {
    console();
}

void console() {
    char num_prog[2];
    while (num_prog[0] != '0') {
        cout << "Select one of the programs and enter it's number:" << endl;
        cout << "0 - Terminate the program." << endl;
        cout << "1 - Adding a node." << endl;
        cout << "2 - Adding a node." << endl;
        cout << "3 - Node search." << endl;
        cout << "4a - Printing a binary tree. Infix version " << endl;
        cout << "4b - Printing a binary tree. Prefix version" << endl;
        cout << "4c - Printing a binary tree. Postfix version" << endl;

        cout << " " << endl;
        cout << ">> ";
        cin >> num_prog;
        cout << " " << endl;

        if (num_prog[0] == '1') {
            int element;
            cout << "Input the value of the new node." << endl;
            cout << ">>  ";
            cin >> element;
            if (IsEmpty) {
                Tree = CreateNode(element, Tree);
                IsEmpty = false;
            }
            else {
                Tree = CreateNode(element, Tree);
            }
            cout << " " << endl;
        }

        if (num_prog[0] == '2') {
            int element;
            cout << "Input the value of the item you want to delete." << endl;
            cout << ">>  ";
            cin >> element;
            DeleteNode(element, Tree, Tree,1);
            cout << " " << endl;
        }

        if (num_prog[0] == '3') {
            int element;
            cout << "Input the value of the node." << endl;
            cout << ">>  ";
            cin >> element;
            Search(element, Tree);
            cout << " " << endl;
        }

        if ((num_prog[0] == '4') && (num_prog[1] == 'a')){
            Printing_infix(Tree);
            cout << " " << endl;
            cout << " " << endl;
        }

        if ((num_prog[0] == '4') && (num_prog[1] == 'b')){
            Printing_prefix(Tree);
            cout << " " << endl;
            cout << " " << endl;
        }

        if ((num_prog[0] == '4') && (num_prog[1] == 'c')){
            Printing_postfix(Tree);
            cout << " " << endl;
            cout << " " << endl;
        }

    }
}

struct Treenode * CreateNode(int value, Treenode *t_ptr) {
    if (t_ptr == nullptr) {
        t_ptr =new Treenode;
        t_ptr->value = value;
        t_ptr->left =  nullptr;
        t_ptr->right = nullptr;
    }else {
        if (value <= t_ptr->value) {
            t_ptr->left = CreateNode(value, t_ptr->left);
        }
        else {
            t_ptr->right = CreateNode(value, t_ptr->right);
        }
    }
    return (t_ptr);
}
void DeleteNode(int value,Treenode *parent_ptr, Treenode *t_ptr, bool IsRight) {
    if (t_ptr == nullptr) {
        return;
    } else {
        if (value > t_ptr->value) {
            DeleteNode(value, t_ptr, t_ptr->right, 1);
        }
        if (value < t_ptr->value) {
            DeleteNode(value, t_ptr, t_ptr->left, 0);
        }
        if (value == t_ptr->value) {
            if ((t_ptr->left == nullptr) && (t_ptr->right == nullptr)){
                if (IsRight) {
                    parent_ptr->right = nullptr;
                }
                else {
                    parent_ptr->left = nullptr;
                }
            }
            if ((t_ptr->left != nullptr) && (t_ptr->right == nullptr)){
                if (IsRight) {
                    parent_ptr->right = t_ptr->left;
                }
                else {
                    parent_ptr->left = t_ptr->left;
                }
            }
            if ((t_ptr->left == nullptr) && (t_ptr->right != nullptr)){
                if (IsRight) {
                    parent_ptr->right = t_ptr->right;
                }
                else {
                    parent_ptr->left = t_ptr->right;
                }
            }
            if ((t_ptr->left != nullptr) && (t_ptr->right != nullptr)){
                if (t_ptr->left->right == nullptr) {
                    t_ptr->value = t_ptr->left->value;
                    t_ptr->left = t_ptr->left->left;
                }
                else {
                    Treenode *ptr = t_ptr->left;
                    Treenode *ptr_parent = t_ptr;
                    while (ptr->right->right != nullptr) {
                        ptr = ptr->right;
                        ptr_parent = ptr_parent->right;
                    }
                    t_ptr->value = ptr->right->value;
                    DeleteNode(ptr->right->value,ptr_parent, ptr, 1);
                }
            }
        }
    }
}


void Printing_infix(Treenode *t_ptr) {
    if (t_ptr != nullptr) {
        Printing_infix(t_ptr->left);
        cout << t_ptr->value << " -> ";
        Printing_infix(t_ptr->right);
    }
}

void Printing_prefix(Treenode *t_ptr) {
    if (t_ptr!=nullptr) {
        cout << t_ptr->value << " -> ";
        Printing_prefix(t_ptr->left);
        Printing_prefix(t_ptr->right);
    }
}

void Printing_postfix(Treenode *t_ptr) {
    if (t_ptr!=nullptr) {
        Printing_postfix(t_ptr->left);
        Printing_postfix(t_ptr->right);
        cout << t_ptr->value << " -> ";
    }
}

void Search(int value, Treenode *t_ptr) {
    if (t_ptr->value == value) {
        cout << value << endl;
    }
    else {
        cout << t_ptr -> value << " -> ";
        if (t_ptr->value < value) {
            if (t_ptr->right == nullptr) {
                cout << " " << endl;
                cout << " " << endl;
                cout << "There is no such element in the tree." << endl;
                return;
            }
            else {
                Search(value, t_ptr->right);
            }
        }
        else {
            if (t_ptr->left == nullptr) {
                cout << " " << endl;
                cout << " " << endl;
                cout << "There is no such element in the tree." << endl;
                return;
            }
            else {
                Search(value, t_ptr->left);
            }
        }
    }
    if ((t_ptr->left == nullptr) && (t_ptr->right == nullptr)){
        cout << " " << endl;
        cout << " " << endl;
        cout << "There is no such element in the tree." << endl;
        return;
    }
}
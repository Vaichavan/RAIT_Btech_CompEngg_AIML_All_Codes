#include <iostream.h>
#include <conio.h>  // For Turbo C++ specific functions
#include <string.h>  // For strcat and strcpy

struct Node {
    int data;
    Node *parent;
    Node *left;
    Node *right;
    int color;
};

typedef Node *NodePtr;

class RedBlackTree {
private:
    NodePtr root;
    NodePtr TNULL;

    inline void initializeNULLNode(NodePtr node, NodePtr parent) {
        node->data = 0;
        node->parent = parent;
        node->left = NULL;
        node->right = NULL;
        node->color = 0;
    }

    inline void preOrderHelper(NodePtr node) {
        if (node != TNULL) {
            cout << node->data << " ";
            preOrderHelper(node->left);
            preOrderHelper(node->right);
        }
    }

    inline void inOrderHelper(NodePtr node) {
        if (node != TNULL) {
            inOrderHelper(node->left);
            cout << node->data << " ";
            inOrderHelper(node->right);
        }
    }

    inline void postOrderHelper(NodePtr node) {
        if (node != TNULL) {
            postOrderHelper(node->left);
            postOrderHelper(node->right);
            cout << node->data << " ";
        }
    }

    inline NodePtr searchTreeHelper(NodePtr node, int key) {
        if (node == TNULL || key == node->data) {
            return node;
        }
        if (key < node->data) {
            return searchTreeHelper(node->left, key);
        }
        return searchTreeHelper(node->right, key);
    }

    inline void rbTransplant(NodePtr u, NodePtr v) {
        if (u->parent == NULL) {
            root = v;
        } else if (u == u->parent->left) {
            u->parent->left = v;
        } else {
            u->parent->right = v;
        }
        v->parent = u->parent;
    }

    inline void deleteFix(NodePtr x) {
        NodePtr s;
        while (x != root && x->color == 0) {
            if (x == x->parent->left) {
                s = x->parent->right;
                if (s->color == 1) {
                    s->color = 0;
                    x->parent->color = 1;
                    leftRotate(x->parent);
                    s = x->parent->right;
                }
                if (s->left->color == 0 && s->right->color == 0) {
                    s->color = 1;
                    x = x->parent;
                } else {
                    if (s->right->color == 0) {
                        s->left->color = 0;
                        s->color = 1;
                        rightRotate(s);
                        s = x->parent->right;
                    }
                    s->color = x->parent->color;
                    x->parent->color = 0;
                    s->right->color = 0;
                    leftRotate(x->parent);
                    x = root;
                }
            } else {
                s = x->parent->left;
                if (s->color == 1) {
                    s->color = 0;
                    x->parent->color = 1;
                    rightRotate(x->parent);
                    s = x->parent->left;
                }
                if (s->right->color == 0 && s->right->color == 0) {
                    s->color = 1;
                    x = x->parent;
                } else {
                    if (s->left->color == 0) {
                        s->right->color = 0;
                        s->color = 1;
                        leftRotate(s);
                        s = x->parent->left;
                    }
                    s->color = x->parent->color;
                    x->parent->color = 0;
                    s->left->color = 0;
                    rightRotate(x->parent);
                    x = root;
                }
            }
        }
        x->color = 0;
    }

    inline void insertFix(NodePtr k) {
        NodePtr u;
        while (k->parent->color == 1) {
            if (k->parent == k->parent->parent->right) {
                u = k->parent->parent->left;
                if (u->color == 1) {
                    u->color = 0;
                    k->parent->color = 0;
                    k->parent->parent->color = 1;
                    k = k->parent->parent;
                } else {
                    if (k == k->parent->left) {
                        k = k->parent;
                        rightRotate(k);
                    }
                    k->parent->color = 0;
                    k->parent->parent->color = 1;
                    leftRotate(k->parent->parent);
                }
            } else {
                u = k->parent->parent->right;
                if (u->color == 1) {
                    u->color = 0;
                    k->parent->color = 0;
                    k->parent->parent->color = 1;
                    k = k->parent->parent;
                } else {
                    if (k == k->parent->right) {
                        k = k->parent;
                        leftRotate(k);
                    }
                    k->parent->color = 0;
                    k->parent->parent->color = 1;
                    rightRotate(k->parent->parent);
                }
            }
            if (k == root) {
                break;
            }
        }
        root->color = 0;
    }

    inline void printHelper(NodePtr root, char* indent, int last) {
        if (root != TNULL) {
            cout << indent;
            if (last) {
                cout << "R----";
                strcat(indent, "   ");
            } else {
                cout << "L----";
                strcat(indent, "|  ");
            }
            char sColor[6];
            strcpy(sColor, root->color ? "RED" : "BLACK");
            cout << root->data << "(" << sColor << ")" << endl;
            char indentLeft[50];
            strcpy(indentLeft, indent);
            printHelper(root->left, indentLeft, 0);
            printHelper(root->right, indent, 1);
        }
    }

public:
    RedBlackTree() {
        TNULL = new Node;
        TNULL->color = 0;
        TNULL->left = NULL;
        TNULL->right = NULL;
        root = TNULL;
    }

    inline void preorder() {
        preOrderHelper(this->root);
        cout << endl;
    }

    inline void inorder() {
        inOrderHelper(this->root);
        cout << endl;
    }

    inline void postorder() {
        postOrderHelper(this->root);
        cout << endl;
    }

    inline NodePtr searchTree(int k) {
        return searchTreeHelper(this->root, k);
    }

    NodePtr minimum(NodePtr node) {
        while (node->left != TNULL) {
            node = node->left;
        }
        return node;
    }

    NodePtr maximum(NodePtr node) {
        while (node->right != TNULL) {
            node = node->right;
        }
        return node;
    }

    NodePtr successor(NodePtr x) {
        if (x->right != TNULL) {
            return minimum(x->right);
        }
        NodePtr y = x->parent;
        while (y != TNULL && x == y->right) {
            x = y;
            y = y->parent;
        }
        return y;
    }

    NodePtr predecessor(NodePtr x) {
        if (x->left != TNULL) {
            return maximum(x->left);
        }
        NodePtr y = x->parent;
        while (y != TNULL && x == y->left) {
            x = y;
            y = y->parent;
        }
        return y;
    }

    void leftRotate(NodePtr x) {
        NodePtr y = x->right;
        x->right = y->left;
        if (y->left != TNULL) {
            y->left->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == NULL) {
            this->root = y;
        } else if (x == x->parent->left) {
            x->parent->left = y;
        } else {
            x->parent->right = y;
        }
        y->left = x;
        x->parent = y;
    }

    void rightRotate(NodePtr x) {
        NodePtr y = x->left;
        x->left = y->right;
        if (y->right != TNULL) {
            y->right->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == NULL) {
            this->root = y;
        } else if (x == x->parent->right) {
            x->parent->right = y;
        } else {
            x->parent->left = y;
        }
        y->right = x;
        x->parent = y;
    }

    void insert(int key) {
        NodePtr node = new Node;
        node->parent = NULL;
        node->data = key;
        node->left = TNULL;
        node->right = TNULL;
        node->color = 1;

        NodePtr y = NULL;
        NodePtr x = this->root;

        while (x != TNULL) {
            y = x;
            if (node->data < x->data) {
                x = x->left;
            } else {
                x = x->right;
            }
        }

        node->parent = y;
        if (y == NULL) {
            root = node;
        } else if (node->data < y->data) {
            y->left = node;
        } else {
            y->right = node;
        }

        if (node->parent == NULL) {
            node->color = 0;
            return;
        }

        if (node->parent->parent == NULL) {
            return;
        }

        insertFix(node);
    }

    void deleteNode(int data) {
        NodePtr node = searchTreeHelper(this->root, data);
        if (node == TNULL) {
            cout << "Node not found" << endl;
            return;
        }
        NodePtr y = node;
        NodePtr x;
        int yOriginalColor = y->color;
        if (node->left == TNULL) {
            x = node->right;
            rbTransplant(node, node->right);
        } else if (node->right == TNULL) {
            x = node->left;
            rbTransplant(node, node->left);
        } else {
            y = minimum(node->right);
            yOriginalColor = y->color;
            x = y->right;
            if (y->parent == node) {
                x->parent = y;
            } else {
                rbTransplant(y, y->right);
                y->right = node->right;
                y->right->parent = y;
            }
            rbTransplant(node, y);
            y->left = node->left;
            y->left->parent = y;
            y->color = node->color;
        }
        delete node;
        if (yOriginalColor == 0) {
            deleteFix(x);
        }
    }

    void printTree() {
        if (root) {
            char indent[50] = "";
            printHelper(this->root, indent, 1);  // Use 1 for true
        }
    }
};

void main() {
    clrscr();  // Clear the screen for Turbo C++
    RedBlackTree bst;

    int choice, value;
    while (1) {  // Changed from while (true) to while (1)
        cout << "Red-Black Tree Operations:\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Print Tree\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the number to insert: ";
                cin >> value;
                bst.insert(value);
                break;
            case 2:
                cout << "Enter the number to delete: ";
                cin >> value;
                bst.deleteNode(value);
                break;
            case 3:
                bst.printTree();
                break;
            case 4:
                cout << "Exiting the program...\n";
                getch();  // Wait for user input before closing
                return;
            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }

        cout << endl;
    }
}


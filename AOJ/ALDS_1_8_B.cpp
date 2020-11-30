#include<bits/stdc++.h>

using namespace std;

// ノード型
struct Node {
    int key;
    Node *parent, *left, *right;

    Node() {
        parent = NULL, left = NULL, right = NULL;
    }
};


// 二分探索木
struct BinarySearchTree {
    Node *root;
    
    BinarySearchTree() { 
        root = NULL;
    }

    // 要素の挿入
    void insert(int num) {
        Node *x, *y, *z;
        z = new Node;
        z->key = num;
        y = NULL;
        x = root;

        while (x != NULL) {
            y = x;
            if (z->key < x->key) {
                x = x->left;
            } else {
                x = x->right;
            }
        }

        z->parent = y;

        if (y == NULL) {
            root = z;
        } else if (z->key < y->key) {
            y->left = z;
        } else {
            y->right = z;
        }
    }

    // 要素の検索
    bool find(int num) {
        Node *tmp = root;
        
        while (tmp != NULL) {
            if (tmp->key == num) {
                return true;
            }

            if (tmp->key > num) {
                tmp = tmp->left;
            } else {
                tmp = tmp->right;
            }
        }

        return false;
    }

    void print() {
        Inorder(root);
        cout << endl;
        Preorder(root);
        cout << endl;
    }

    void Preorder(Node *s) {
        if (s == NULL) {
            return;
        }
 
        cout << " " << s->key;
        Preorder(s->left);
        Preorder(s->right);
    }

    void Inorder(Node *s) {
        if (s == NULL) {
            return;
        }
 
        Inorder(s->left);
        cout << " " << s->key;
        Inorder(s->right);  
    }

    void Postorder(Node *s) {
        if (s == NULL) {
            return;
        }
 
        Postorder(s->left);
        Postorder(s->right); 
        cout << " " << s->key;
    }
};


int main() {
    int m;
    cin >> m;

    string s;
    int v;

    BinarySearchTree Tree;

    for (int i = 0; i < m; i++) {
        cin >> s;
        
        if (s == "insert") {
            cin >> v;
            Tree.insert(v);
        } else if (s == "find") {
            cin >> v;
            if (Tree.find(v) == true) {
                cout << "yes" << endl;
            } else {
                cout << "no" << endl;
            }
        } else if (s == "print") {
            Tree.print();
        }
    }

    return 0;
}
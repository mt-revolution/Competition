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

    // 要素の削除
    void delete_(int num) {
        Node *tmp = root;
        Node *z;
        
        while (tmp != NULL) {
            if (tmp->key == num) {
                z = tmp;
                
                // zの左の子がNULLの場合
                if (z->left == NULL) {
                    Replace(z, z->right);
                // zの右の子がNULLの場合
                } else if (z->right == NULL) {
                    Replace(z, z->left);                  
                // zの両方の子が非NULLの場合(2つの子を持つ場合)
                } else {
                    Node *y = min_node(z->right);
                    z->key = y->key;

                    // yの左の子がNULLの場合
                    if (y->left == NULL) {
                        Replace(y, y->right);
                    // yの右の子がNULLの場合
                    } else if (y->right == NULL) {
                        Replace(y, y->left);
                    }
                }

                break;
            }

            if (tmp->key > num) {
                tmp = tmp->left;
            } else {
                tmp = tmp->right;
            }
        }
    }

    // ノードnをmに置き換える
    void Replace(Node *n, Node *m) {
        Node *p = n->parent;
        if (m != NULL) {
            m->parent = p;
        }

        // nが根のとき
        if (n == root) {
            root = m;
        // nがpの左の子のとき
        } else if (p->left == n) {
            p->left = m;
        // nがpの右の子のとき
        } else {
            p->right = m;
        }
    }

    // 根sの部分木の一番左の(最小)ノードを返す
    Node *min_node(Node *s) {
        Node *tmp = s;
        while (tmp->left != NULL) {
            tmp = tmp->left;
        }

        return tmp;
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
        } else if (s == "delete") {
            cin >> v;
            Tree.delete_(v);
        } else if (s == "print") {
            Tree.print();
        }
    }

    return 0;
}
#include<bits/stdc++.h>

using namespace std;


// 二分木構造
struct BinaryTree {
    vector<pair<int, int>> children;
    vector<int> parent;
    
    BinaryTree(int N) { 
        children.assign(N, make_pair(-1, -1));
        parent.assign(N, -1);
    }

    // 子要素を追加
    void add_child(int u, int v1, int v2) {
        children[u] = make_pair(v1, v2);
        if (v1 != -1) {
            parent[v1] = u;   
        }

        if (v2 != -1) {
            parent[v2] = u;   
        }
    }

    // 要素の種類を判定
    string type(int node) {
        if (parent[node] == -1) {
            return "root";
        } else if (children[node].first == -1 && children[node].second == -1) {
            return "leaf";
        } else {
            return "internal node";
        }
    }

    int sibling(int node) {
        if (parent[node] == -1) {
            return -1;
        }

        int i1 = children[parent[node]].first;
        int i2 = children[parent[node]].second;

        if (i1 == node) {
            return i2;
        } 
        
        return i1;
    }

    int degree(int node) {
        if (children[node].first == -1 && children[node].second == -1) {
            return 0;
        }
        if (children[node].first != -1 && children[node].second != -1) {
            return 2;
        }

        return 1;
    }

    void Preorder(int s) {
        if (s == -1) {
            return;
        }
 
        cout << " " << s;
        Preorder(children[s].first);
        Preorder(children[s].second);
    }

    void Inorder(int s) {
        if (s == -1) {
            return;
        }
 
        Inorder(children[s].first);
        cout << " " << s;
        Inorder(children[s].second);  
    }

    void Postorder(int s) {
        if (s == -1) {
            return;
        }
 
        Postorder(children[s].first);
        Postorder(children[s].second); 
        cout << " " << s;
    }
};


int main() {
    int n;
    cin >> n;

    int u, v1, v2;

    BinaryTree Tree(n);

    for (int i = 0; i < n; i++) {
        cin >> u >> v1 >> v2;
        Tree.add_child(u, v1, v2);
    }

    int root;

    // 根の判定
    for (int i = 0; i < n; i++) {
        if (Tree.type(i) == "root") {
            root = i;
        }
    }

    cout << "Preorder" << endl;
    Tree.Preorder(root);
    cout << endl;

    cout << "Inorder" << endl;
    Tree.Inorder(root);
    cout << endl;

    cout << "Postorder" << endl;
    Tree.Postorder(root);
    cout << endl;

    return 0;
}
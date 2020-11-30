#include<bits/stdc++.h>

using namespace std;

int H;
int error = 2000000001;


// 完全二分木
struct CompleteBinaryTree {
    vector<int> node;

    CompleteBinaryTree() {
        node.assign({-1});
    }

    void add(int num) {
        node.push_back(num);
    }

    int parent(int id) {
        if (id/2 == 0) {
            return error;
        }

        return node[id/2];
    }

    int left(int id) {
        if (2*id > H) {
            return error;
        }

        return node[2*id];
    }

    int right(int id) {
        if (2*id+1 > H) {
            return error;
        }

        return node[2*id+1];
    }
};


int main() {
    cin >> H;

    int v;

    CompleteBinaryTree Tree;

    for (int i = 1; i <= H; i++) {
        cin >> v;
        Tree.add(v);
    }

    for (int i = 1; i <= H; i++) {
        cout << "node " << i << ": key = " << Tree.node[i] << ", ";
        if (Tree.parent(i) != error) {
            cout << "parent key = " << Tree.parent(i) << ", ";
        }
        if (Tree.left(i) != error) {
            cout << "left key = " << Tree.left(i) << ", ";
        }
        if (Tree.right(i) != error) {
            cout << "right key = " << Tree.right(i) << ", ";
        }
        cout << endl;
    }

    return 0;
}
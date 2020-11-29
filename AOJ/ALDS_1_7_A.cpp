#include<bits/stdc++.h>

using namespace std;

int n;

// 根付き木構造
struct Tree {
    vector<vector<int>> children;
    vector<int> depth;
    vector<int> parent;
    
    Tree(int N) { 
        children.assign(N, vector<int>{});
        depth.assign(N, -1);
        parent.assign(N, -1);
    }

    // 子要素を追加
    void add_child(int u, int v) {
        children[u].push_back(v);
        parent[v] = u;
    }

    // BFSで深さを計算
    void calc_depth() {
        int root;

        // 根を求める
        for (int i = 0; i < n; i++) {
            if (parent[i] == -1) {
                root = i;
                break;
            }
        }

        queue<int> node;
        int u;

        depth[root] = 0;
        node.push(root);

        while (node.empty() == false) {
            u = node.front();
            node.pop();

            // u から行ける各頂点 v について再帰的に探索
            for (auto v : children[u]) { 
                if (depth[v] == -1) {
                    depth[v] = depth[u] + 1;
                    node.push(v);
                }
            }           
        }
    }

    // 要素の種類を判定
    string type(int node) {
        if (parent[node] == -1) {
            return "root";
        } else if (children[node].empty() == true) {
            return "leaf";
        } else {
            return "internal node";
        }
    }
};


int main() {
    cin >> n;

    int node;
    int k, u, v;

    Tree Tree(n);

    for (int i = 0; i < n; i++) {
        cin >> u >> k;

        for (int i = 0; i < k; i++) {
            cin >> v;
            Tree.add_child(u, v);
        }
    }

    Tree.calc_depth();

    for (int i = 0; i < n; i++) {
        cout << "node " << i << ": parent = " << Tree.parent[i] << ", depth = " << Tree.depth[i] << ", " << Tree.type(i) << ", [";

        for (int j = 0; j < Tree.children[i].size(); j++) {
            if (j == 0) {
                cout << Tree.children[i][j];
                continue;
            }
            cout << ", " << Tree.children[i][j];
        }

        cout << "]" << endl;
    }

    return 0;
}
#include<bits/stdc++.h>

using namespace std;

int n;

// 二分木構造
struct BinaryTree {
    vector<vector<int>> children;
    vector<int> depth;
    vector<int> height;
    vector<int> parent;
    
    BinaryTree(int N) { 
        children.assign(N, vector<int>{});
        depth.assign(N, -1);
        height.assign(N, -1);
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

    // BFSで高さを計算
    void calc_height() {
        for (int i = 0; i < n; i++) {
            if (children[i].empty() == true) {
                queue<int> node;
                int u, v;

                height[i] = 0;
                node.push(i);

                while (node.empty() == false) {
                    u = node.front();
                    node.pop();

                    // u から行ける各頂点 v について再帰的に探索
                    v = parent[u];

                    if (v == -1) {
                        break;
                    }
                    height[v] = max(height[v], height[u] + 1);
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

    int sibling(int node) {
        int answer = -1;
        if (parent[node] == -1) {
            return answer;
        }

        for (auto i : children[parent[node]]) {
            if (i != node) {
                answer = i;
                break;
            }
        }

        return answer;
    }

    int degree(int node) {
        return children[node].size();
    }
};


int main() {
    cin >> n;

    int node;
    int k, u, v;

    BinaryTree Tree(n);

    for (int i = 0; i < n; i++) {
        cin >> u;

        for (int i = 0; i < 2; i++) {
            cin >> v;
            if (v == -1) {
                continue;
            }

            Tree.add_child(u, v);
        }
    }

    Tree.calc_depth();
    Tree.calc_height();

    for (int i = 0; i < n; i++) {
        cout << "node " << i << ": parent = " << Tree.parent[i] << ", sibling = " << Tree.sibling(i) << ", degree = " << Tree.degree(i) << ", depth = " << Tree.depth[i] << ", height = " << Tree.height[i] << ", " << Tree.type(i) << endl;
    }

    return 0;
}
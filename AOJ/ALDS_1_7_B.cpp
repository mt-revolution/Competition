#include<bits/stdc++.h>

using namespace std;

int n;

// 二分木構造
struct BinaryTree {
    vector<pair<int, int>> children;
    vector<int> depth;
    vector<int> height;
    vector<int> parent;
    
    BinaryTree(int N) { 
        children.assign(N, pair<int, int>{-1, -1});
        depth.assign(N, -1);
        height.assign(N, -1);
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
        int u, v1, v2;

        depth[root] = 0;
        node.push(root);

        while (node.empty() == false) {
            u = node.front();
            node.pop();

            // u から行ける各頂点 v について再帰的に探索
            v1 = children[u].first;
            if (depth[v1] == -1) {
                depth[v1] = depth[u] + 1;
                node.push(v1);
            }           
            v2 = children[u].second;
            if (depth[v2] == -1) {
                depth[v2] = depth[u] + 1;
                node.push(v2);
            }  
        }
    }

    // BFSで高さを計算
    void calc_height() {
        for (int i = 0; i < n; i++) {
            if (children[i].first == -1) {
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
        } else if (children[node].first == -1) {
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
        if (children[node].first == -1) {
            return 0;
        }
        if (children[node].second != -1) {
            return 2;
        }

        return 1;
    }

    void Preorder(int s) {
        if (s == -1) {
            return;
        }

        int v1 = children[s].first;
        int v2 = children[s].second;
 
        cout << " " << s;
        Preorder(v1);
        Preorder(v2);
    }
};


int main() {
    cin >> n;

    int node;
    int u, v1, v2;

    BinaryTree Tree(n);

    for (int i = 0; i < n; i++) {
        cin >> u >> v1 >> v2;   
        Tree.add_child(u, v1, v2);
    }

    // Tree.calc_depth();
    // Tree.calc_height();
    // Tree.Preorder(0);

    for (int i = 0; i < n; i++) {
        cout << "node " << i << ": parent = " << Tree.parent[i] << ", sibling = " << Tree.sibling(i) << ", degree = " << Tree.degree(i) << ", depth = " << Tree.depth[i] << ", height = " << Tree.height[i] << ", " << Tree.type(i) << endl;
    }

    return 0;
}
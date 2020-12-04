#include<bits/stdc++.h>

using namespace std;

// Union-Find木
struct UnionFind {
    vector<int> par; // par[i]:iの親の番号

    UnionFind(int N) : par(N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) {
            par[i] = i;
        }
    }

    int root(int x) { // データxが属する木の根を再帰で得る
        if (par[x] == x) {
            return x;
        }

        return par[x] = root(par[x]);
    }

    void unite(int x, int y) { // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) {
            return; //xとyの根が同じ(=同じ木にある)時はそのまま
        }

        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

int main() {
    int n,m;
    cin >> n >> m;
    
    UnionFind U(n);

    int s,t;
    
    for (int i = 0; i < m; i++) {
        cin >> s >> t;
        U.unite(s, t);
    }

    int q;
    cin >> q;
    
    for (int i = 0; i < q; i++) {
        cin >> s >> t;
        if (U.same(s, t) == true) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
    
    return 0;
}
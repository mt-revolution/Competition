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
    int n,q;
    cin >> n >> q;

    int c,x,y;

    UnionFind U(n);
    vector<int> answer;

    for(int i = 0; i < q; i++) {
        cin >> c >> x >> y;

        if(c == 0) {
            U.unite(x, y);
        } else {
            if(U.same(x, y) == true) {
                answer.push_back(1);
            } else {
                answer.push_back(0);
            }
        }
    }

    for(auto i : answer) {
        cout << i << endl;
    }

	return 0;
}
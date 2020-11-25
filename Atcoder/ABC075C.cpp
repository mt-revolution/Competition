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
    int N,M;
    cin >> N >> M;

    vector<int> a(M), b(M);
    int count = 0;

    for(int i = 0; i < M; i++) {
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
    }

    // それぞれの辺について取り除く
    for(int i = 0; i < M; i++) {
        UnionFind U(N);

        // それ以外の辺で繋がれる頂点を併合する
        for(int j = 0; j < M; j++) {
            if(j == i) {
                continue;
            }

            U.unite(a[j], b[j]);
        }

        // 取り除いた辺で繋がれる頂点が連結されているか判断する
        if(U.same(a[i], b[i]) == false) {
            count++;
        }
    }

    cout << count << endl;
	return 0;
}
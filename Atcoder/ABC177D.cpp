#include<bits/stdc++.h>
 
using namespace std;

// Union-Find木
struct UnionFind {
    vector<int> par; // par[i]:iの親の番号
    vector<long long> siz; // siz[i]:iが属する木の大きさ

    UnionFind(int N) : par(N), siz(N, 1) { //最初は全てが根であるとして初期化
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

        siz[ry] += siz[rx];
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }

    long long size(int x) {
        return siz[root(x)];
    }
};

 
int main() {
	int N,M;
    cin >> N >> M;

    int A,B;

    UnionFind U(N+1);

    for (int i = 0; i < M; i++) {
        cin >> A >> B;
        U.unite(A,B);
    }

    long long answer = 0;

    for (int i = 1; i <= N; i++) {
        answer = max(answer, U.size(i));
    }

    cout << answer << endl;
	return 0;
}
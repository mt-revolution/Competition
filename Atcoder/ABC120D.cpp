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
    long long N;
    int M;
    cin >> N >> M;

    vector<long long> A(M), B(M);
    vector<long long> answer(M);

    for (int i = 0; i < M; i++) {
        cin >> A[i] >> B[i];
        A[i]--, B[i]--;
    }

    UnionFind U(N);

    answer[M-1] = N*(N-1) / 2;

    // 後ろから処理
    for (int i = M-2; i >= 0; i--) {
        if (U.same(A[i+1], B[i+1]) == true) {
            answer[i] = answer[i+1];
        } else {
            answer[i] = answer[i+1] - U.size(A[i+1]) * U.size(B[i+1]);
            U.unite(A[i+1], B[i+1]);
        }
    }

    for (auto i : answer) {
        cout << i << endl;
    }

	return 0;
}
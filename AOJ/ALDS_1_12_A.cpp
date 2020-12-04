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
    int n;
    cin >> n;
    
    // クラスカル法
    // 辺の長さを負にした値と2点を大きい順に格納(つまり辺の長さが小さい順)
    priority_queue<tuple<long long, int, int>> S;
    tuple<long long, int, int> tmp;

    long long a;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a;
            if (a != -1) {
                S.push(make_tuple(-a, i, j));     
            }
        }
    }

    // UnionFind木を使って集合を管理
    UnionFind F(n);
    long long answer = 0;

    while(S.empty() == false) {
        // 辺の長さが一番小さい2点を取り出す
        tmp = S.top();
        S.pop();

        // 違うUnion-Find木に属していた場合結合し、辺の重みを合計する
        if(F.same(get<1>(tmp), get<2>(tmp)) == false) {
            F.unite(get<1>(tmp), get<2>(tmp));
            answer += -get<0>(tmp);
        }
    }

    cout << answer << endl;   
    return 0;
}
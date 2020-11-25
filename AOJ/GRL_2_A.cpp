#include<bits/stdc++.h>

using namespace std;

struct UnionFind {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

    UnionFind(int N) : par(N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) {
            par[i] = i;
        }
    }

    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
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
    int V, E;
    cin >> V >> E;
    
    int s, t, w;
    // 各始点に対しての(終点、重み)の隣接リスト
    vector<vector<pair<int, long long>>> length(V, vector<pair<int, long long>>{});

    priority_queue<tuple<long long, int, int>> S;
    tuple<long long, int, int> tmp;

    for(int i = 0; i < E; i++) {
        cin >> s >> t >> w;
        length[s].push_back(pair<int, long long>(t, w));
        // 小さい順に取り出すため負にして優先度付きキューに入れる
        S.push(make_tuple(-w, s, t));
    }

    // UnionFind木を使って集合を管理
    UnionFind F(V);

    long long answer = 0;

    // クラスカル法
    while(S.empty() == false) {
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
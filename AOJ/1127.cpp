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
    int n;
    vector<double> answer;

    while(1) {
        cin >> n;
        if(n == 0) {
            break;
        }

        vector<double> X(n), Y(n), Z(n), R(n);
        priority_queue<tuple<double, int, int>> S;
        tuple<double, int, int> tmp;
        double dist;

        for(int i = 0; i < n; i++) {
            cin >> X[i] >> Y[i] >> Z[i] >> R[i];
        }

        // UnionFind木を使って集合を管理
        UnionFind F(n);

        for(int i = 0; i < n-1; i++) {
            for(int j = i+1; j < n; j++) {
                dist = sqrt(pow(X[i]-X[j], 2.0) + pow(Y[i]-Y[j], 2.0) + pow(Z[i]-Z[j], 2.0));

                // ステーション間が離れている場合
                if(dist > R[i] + R[j]) {
                    S.push(make_tuple(-(dist - (R[i] + R[j])), i, j));
                    
                // ステーション同士が接触している場合
                } else {
                    F.unite(i, j);
                }
            }
        }

        double count = 0;

        // クラスカル法
        while(S.empty() == false) {
            tmp = S.top();
            S.pop();

            // 違うUnion-Find木に属していた場合結合し、辺の重みを合計する
            if(F.same(get<1>(tmp), get<2>(tmp)) == false) {
                F.unite(get<1>(tmp), get<2>(tmp));
                count += -get<0>(tmp);
            }
        }

        answer.push_back(count);
    }

    for(auto i : answer) {
        cout << fixed << setprecision(3) << i << endl;
    }
	return 0;
}
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

	vector<long long> a(N), b(N);
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < N; i++) {
		cin >> b[i];
	}

	int c,d;
	UnionFind graph(N);

	for (int i = 0; i < M; i++) {
		cin >> c >> d;
		c--, d--;
		graph.unite(c, d);
	}

	bool flag = true;
	vector<long long> sum_a(N, 0);
	vector<long long> sum_b(N, 0);
	vector<int> root(N);

	for (int i = 0; i < N; i++) {
		root[i] = graph.root(i);
	}

	for (int i = 0; i < N; i++) {
		sum_a[root[i]] += a[i];
		sum_b[root[i]] += b[i];
	}

	for (int i = 0; i < N; i++) {
		if (sum_a[root[i]] != sum_b[root[i]]) {
			flag = false;
			break;
		}
	}

	if (flag == true) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}

	return 0;
}
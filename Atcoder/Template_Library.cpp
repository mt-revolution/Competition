#include<bits/stdc++.h>

using namespace std;

// GCD(最大公約数)をユークリッドの互除法で求める
long long gcd(long long x, long long y) {
    if(x % y == 0) {
        return y;
    } else {
        return gcd(y, x % y);
    }
}

// 回文判定
bool is_palindrome(string S) {
    int N = S.size();
    for (int i = 0; i < N; i++) {
        if (S[i] != S[N-1-i]) {
            return false;
        }
    }

    return true;
}

// 深さ優先探索(探索時刻の記録)
struct dfs {
    vector<vector<int>> G;
    vector<int> d;
    vector<int> f;
    int t;

    dfs(int N) {
        G.assign(N, vector<int>{});
        d.assign(N, 0);
        f.assign(N, 0);
        t = 1;
    };

    void make_edge(int u, int v) {
        G[u].push_back(v);
    }

    void make_twoedge(int u, int v) {
        G[u].push_back(v);
        G[v].push_back(u);
    }

    void do_dfs(int u) {
        d[u] = t;
        t++;

        // u から行ける各頂点 v について再帰的に探索
        for (auto v : G[u]) { 
            if (d[v] != 0) {
                continue;
            }

            do_dfs(v);

        }

        f[u] = t;
        t++;
    }
};



// 深さ優先探索(島の発見)
struct dfs {
    vector<vector<int>> map;
    vector<vector<bool>> seen;
    vector<int> di = {1, 1, 1, 0, 0, -1, -1, -1};
    vector<int> dj = {1, 0, -1, 1, -1, 1, 0, -1};
    int x, y;

    dfs(int H, int W) {
        map.assign(H+2, vector<int>(W+2, 0));
        seen.assign(H+2, vector<bool>(W+2, false));
    };

    void set(int i, int j, int in) {
        map[i][j] = in;
    }

    void do_dfs(int i, int j) {
        seen[i][j] = true;

        // (i,j) に隣接している地点を再帰的に探索
        for (int k = 0; k < 8; k++) {
            x = i + di[k], y = j + dj[k];

            if (map[x][y] == 0 || seen[x][y] == true) {
                continue;
            }

            do_dfs(x, y);
        }
    }
};


int N,M,Q;
vector<int> a,b,c,d;
int answer = 0;

// 広義単調増加列を作る
void dfs(vector<int> A) {
	if (A.size() == N+1) {
		int count = 0;
		for (int i = 0; i < Q; i++) {
			if (A[b[i]] - A[a[i]] == c[i]) {
				count += d[i];
			}
		}

		answer = max(answer, count);
		return;
	}

	A.push_back(A.back());
	while (A.back() <= M) {
		dfs(A);
		A.back()++;
	}
}


// dpのメモ化再帰
double rec(int A, int B, int C, vector<vector<vector<double>>> &dp) {
	double sum = (double)(A + B + C);

	// ベースケース、いずれかが100枚になったとき
	if (A == 100 || B == 100 || C == 100) {
		return 0;
	}

	// 既に値が計算されているとき
	if (dp[A][B][C] != -1.0) {
		return dp[A][B][C];
	}

	// 値が計算されていないときは計算して配列に格納
	return dp[A][B][C] = (double)A/sum * (rec(A+1, B, C, dp) + 1) + (double)B/sum * (rec(A, B+1, C, dp) + 1) + (double)C/sum * (rec(A, B, C+1, dp) + 1);
}




// 幅優先探索(最短距離の計算)
struct bfs {
    vector<vector<int>> G;
    vector<int> distance;

    bfs(int N) {
        G.assign(N, vector<int>{});
        distance.assign(N, -1);
    };

    void make_edge(int u, int v) {
        G[u].push_back(v);
    }

    void make_twoedge(int u, int v) {
        G[u].push_back(v);
        G[v].push_back(u);
    }

    void do_bfs(int s) {
        queue<int> node;
        int u;

        distance[s] = 0;
        node.push(s);

        while (node.empty() == false) {
            u = node.front();
            node.pop();

            // u から行ける各頂点 v について再帰的に探索
            for (auto v : G[u]) { 
                if (distance[v] == -1) {
                    distance[v] = distance[u] + 1;
                    node.push(v);
                }
            }           
        }
    }
};




// 幅優先探索(二次元迷路の探索)
struct bfs {
    vector<vector<vector<pair<int, int>>>> G;
    vector<vector<int>> distance;

    bfs(int h, int w) {
        G.assign(h, vector<vector<pair<int, int>>>(w, vector<pair<int, int>>{}));
        distance.assign(h, vector<int>(w, 0));
    };

    void make_edge(int ui, int uj, int vi, int vj) {
        G[ui][uj].push_back(make_pair(vi, vj));
    }

    void make_twoedge(int ui, int uj, int vi, int vj) {
        G[ui][uj].push_back(make_pair(vi, vj));
        G[vi][vj].push_back(make_pair(ui, uj));
    }

    void do_bfs(int si, int sj) {
        queue<pair<int, int>> node;
        int ui, uj;

        distance[si][sj] = 1;
        node.push(make_pair(si, sj));

        while (node.empty() == false) {
            ui = node.front().first;
            uj = node.front().second;
            node.pop();

            // (ui, uj) から行ける各マス (vi, vj) について再帰的に探索
            for (auto v : G[ui][uj]) { 
                if (distance[v.first][v.second] == 0) {
                    distance[v.first][v.second] = distance[ui][uj] + 1;
                    node.push(v);
                }
            }           
        }
    }
};



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


// vectorから要素を検索
bool vector_finder(vector<int> vec, int number) {
    auto itr = find(vec.begin(), vec.end(), number);
    size_t index = distance( vec.begin(), itr );
    if (index != vec.size()) { // 発見できたとき
        return true;
    }
    else { // 発見できなかったとき
        return false;
    }
}




// 素因数分解
vector<pair<long long, long long>> prime_factorize(long long N) {
    vector<pair<long long, long long>> prime;
    long long tmp, count;

    tmp = N;

    for (long long a = 2; a * a <= N; a++) {
        if (tmp % a != 0) {
            continue;
        }

        count = 0; // 指数

        // 割れる限り割り続ける
        while (tmp % a == 0) {
            count++;
            tmp /= a;
        }

        // その結果を push
        prime.push_back(make_pair(a, count));
    }

    // 最後に残った数について
    if (tmp != 1) {
        prime.push_back({tmp, 1});
    }
    return prime;
}


// 素数判定
bool is_prime(long long N) {
    if(N == 1) {
        return false;
    }

    for (long long a = 2; a * a <= N; a++) {
        if(N % a == 0) {
            return false;
        }
    }

    return true;
}



// べき乗の余り計算
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) {
            res = res * a % mod;
        }
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

// 負の数にも対応した % 演算
long long mod(long long val, long long m) {
    long long res = val % m;
    if (res < 0) {
        res += m;
    }
    
    return res;
}


// mod. m での a の逆元 a^{-1} を計算する
long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}


int GCD(int a, int b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}



// n個からk個選ぶ組み合わせの場合の数nCk(nが大きいとオーバーフローする)
vector<vector<long long>> comb(int n, int r) {
  vector<vector<long long>> v(n + 1,vector<long long>(n + 1, 0));
  for (int i = 0; i < v.size(); i++) {
    v[i][0] = 1;
    v[i][i] = 1;
  }
  for (int j = 1; j < v.size(); j++) {
    for (int k = 1; k < j; k++) {
      v[j][k] = (v[j - 1][k - 1] + v[j - 1][k]);
    }
  }
  return v;
}



// 二項係数のmod計算
const long long MOD = 1000000007;

const int MAX = 200001;

vector<long long> fac(MAX), finv(MAX), inv(MAX);

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k || n < 0 || k < 0) {
        return 0;
    }
    
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}








int main() {

    // bit全探索
    int n = 3;

    // {0, 1, ..., n-1} の部分集合の全探索
    for (int bit = 0; bit < (1<<n); ++bit) {
        vector<int> S;
        for (int i = 0; i < n; ++i) {
            if (bit & (1<<i)) { // 列挙に i が含まれるか
                S.push_back(i);
            }
        }

        cout << bit << ": {";
        for (int i = 0; i < (int)S.size(); ++i) {
            cout << S[i] << " ";
        }
        cout << "}" << endl;
    }


    // 順列全探索
    vector<int> S(8);

    for(int i = 0; i < 8; i++) {
        S[i] = i;
    }
        
    // 処理
    do {
        

    } while(next_permutation(S.begin(), S.end()));


    // 二分探索
    sort(S.begin(), S.end());

    // 3以上の値のうち一番小さいindexが返される
    auto iter = lower_bound(S.begin(), S.end(), 3);

    // 3より大きい値のうち一番小さいindexが返される
    auto iter = upper_bound(S.begin(), S.end(), 3);
    

    // 小数点以下の桁数指定
    cout << fixed << setprecision(10) << answer << endl;



    // 深さ優先探索
    vector<bool> seen;
    void dfs(const vector<vector<int>> &G, int v) {
        seen[v] = true; // v を訪問済にする

        // v から行ける各頂点 next_v について
        for (auto next_v : G[v]) { 
            if (seen[next_v]) continue; // next_v が探索済だったらスルー
            dfs(G, next_v); // 再帰的に探索
        }
    }


    

    int main() {
        // 頂点数と辺数
        int N, M; 
        cin >> N >> M;

        // グラフ入力受取 (ここでは無向グラフを想定)
        vector<vector<int> G(N);
        for (int i = 0; i < M; i++) {
            int a, b;
            cin >> a >> b;
            G[a].push_back(b);
            G[b].push_back(a);
        }

        // 頂点 0 をスタートとした探索
        seen.assign(N, false);
        dfs(G, 0);
    }


    // 木の場合
    void dfs(vector<vector<int>> &graph, vector<int> &counter, int child, int parent = 0) {
        for(int son : graph[child]) {
            if(son == parent) {
                continue;
            }

            counter[son] += counter[child];
            dfs(graph, counter, son, child);
        }
    }


    
    // 幅優先探索
    // 頂点数と辺数
    int N, M; 
    cin >> N >> M;

    // グラフ入力受取 (ここでは無向グラフを想定)
    vector<vector<int>> G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // BFS のためのデータ構造
    vector<int> dist(N, -1); // 全頂点を「未訪問」に初期化
    queue<int> que;

    // 初期条件 (頂点 0 を初期ノードとする)
    dist[0] = 0;
    que.push(0); // 0 を橙色頂点にする

    // BFS 開始 (キューが空になるまで探索を行う)
    while (!que.empty()) {
        int v = que.front(); // キューから先頭頂点を取り出す
        que.pop();

        // v から辿れる頂点をすべて調べる
        for (int nv : G[v]) {
            if (dist[nv] != -1) continue; // すでに発見済みの頂点は探索しない

            // 新たな白色頂点 nv について距離情報を更新してキューに追加する
            dist[nv] = dist[v] + 1;
            que.push(nv);
        }
    }

    // 結果出力 (各頂点の頂点 0 からの距離を見る)
    for (int v = 0; v < N; ++v) cout << v << ": " << dist[v] << endl;





    // ダイクストラ
    // 各始点に対しての(終点、重み)の隣接リスト
    vector<vector<pair<int, int>>> length(V, vector<pair<int, int>>{});
    vector<int> dist(V, 0);
    vector<int> prev(V, -1);

    // 優先度付き待ち行列を使って高速化
    priority_queue<pair<int, int>> Q;
    int u;

    for(int i = 0; i < E; i++) {
        cin >> s >> t >> d;
        length[s].push_back(pair<int, int>(t, d));
    }

    // 初期条件
    for(int v = 0; v < V; v++) {
        if(v == r) {
            dist[v] = 0;
        } else {
            dist[v] = INF;
        }

        Q.push(pair<int, int>(dist[v], v));
    }
    
    // ダイクストラ開始
    // Qが空になるまで
    while(Q.empty() == false) {
        // Qの中で一番距離が小さい点uを取り出す
        u = Q.top().second;
        Q.pop();

        // uから行けるvについて処理する
        for(auto v : length[u]) {
            if(dist[v.first] > dist[u] + v.second) {
                dist[v.first] = dist[u] + v.second;
                prev[v.first] = u;
                // 距離の小さい方から取り出すために負にしてQに記録
                Q.push(pair<int, int>(-dist[v.first], v.first));
            }
        }
    }

    for(int i = 0; i < V; i++) {
        if(dist[i] == INF) {
            cout << "INF" << endl;
        } else {
            cout << dist[i] << endl;
        }
    }



    // ワーシャルフロイド法
    vector<vector<long long>> graph(V, vector<long long>(V, INF));
    bool flag = false;

    for(int i = 0; i < E; i++) {
        cin >> s >> t >> d;
        graph[s][t] = d;
    }

    for(int i = 0; i < V; i++) {
        graph[i][i] = 0;
    }

    // ワーシャルフロイド法のiからjまで移動するときの最小コストdp[k][i][j]
    vector<vector<long long>> dp(V, vector<long long>(V, INF));

    // 初期条件
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            if(graph[i][j] != INF) {
                dp[i][j] = graph[i][j];
            }
        }
    }

    // dp開始
    for(int k = 0; k < V; k++) {
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                if(dp[i][j] == INF && (dp[i][k] == INF || dp[k][j] == INF)) {
                    dp[i][j] = INF;
                    continue;
                }

                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    // 負の閉路の検出
    for(int i = 0; i < V; i++) {
        if(dp[i][i] < 0) {
            flag = true;
            break;
        }
    }

    if(flag == true) {
        cout << "NEGATIVE CYCLE" << endl;
    } else {
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                if(j > 0) {
                    cout << " ";
                }

                if(dp[i][j] == INF) {
                    cout << "INF";
                    continue;
                }

                cout << dp[i][j];
            }
            cout << endl;
        }
    }




    // クラスカル法
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





    // 累積和
    int N;
    cin >> N;

    vector<long long> A(N);
    vector<long long> S(N+1);

    long long max_resource = 0;


    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    S[0] = 0;
    
    for(int i = 1; i <= N; i++) {
        S[i] = S[i-1] + A[i-1];
    }



    // いもす法
    for(int i = 0; i < n; i++) {
        customer[a[i]] += 1;
        customer[b[i]+1] -= 1;
    }

    for(int i = 1; i < 1000001; i++) {
        customer[i] += customer[i-1];
    }







    // ループを含む状態遷移の対処
    int N;
	long long K;
	cin >> N >> K;

	vector<int> A(N+1);
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
    
    // ワープの変遷
	vector<int> trans;
	// 重複チェック
	vector<int> id(N+1, 0);
	int tmp = 1;
	int next;

	trans.push_back(1);
	id[1] = 1;

	// 変遷の記録をする
	while (1) {
		next = A[tmp];
		if (id[next] == 1) {
			trans.push_back(next);
			break;
		}

		tmp = next;
		id[tmp] = 1;

		trans.push_back(tmp);
	}

	// ループの始まるインデックス
	int loop_start;

	for (int i = 0; i < trans.size() - 1; i++) {
		if (trans[i] == trans.back()) {
			loop_start = i;
			break;
		}
	}
	
	// ループする前の変遷
	vector<int> before;
	// ループの変遷
	vector<int> loop;

	for (int i = 0; i < loop_start; i++) {
		before.push_back(trans[i]);
	}

	for (int i = loop_start; i < trans.size() - 1; i++) {
		loop.push_back(trans[i]);
	}

	long long before_size = before.size(), loop_size = loop.size();

	int answer;

	// ワープ回数が少なくループする前の変遷で決まるとき
	if (K < before_size) {
		answer = before[K];
	// ワープ回数が多くループの変遷で決まるとき
	} else {
		K -= before_size;
		answer = loop[K % loop_size];
	}


    return 0;
}
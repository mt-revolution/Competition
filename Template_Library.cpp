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


// ダイクストラ
struct Graph {
    vector<vector<pair<int, long long>>> G;
    vector<long long> distance;

    Graph(int N) {
        G.assign(N, vector<pair<int, long long>>{});
        distance.assign(N, 1000000000);
    };

    void make_edge(int u, int v, long long dist) {
        G[u].push_back(make_pair(v, dist));
    }

    void make_twoedge(int u, int v, long long dist) {
        G[u].push_back(make_pair(v, dist));
        G[v].push_back(make_pair(u, dist));
    }

    // ダイクストラ
    void do_dijkstra(int s) {
        // 優先度付き待ち行列を使って高速化
		priority_queue<pair<long long, int>> Q;
		int u;

		// 初期条件
        distance[s] = 0;
		for(int v = 0; v < n; v++) {
			Q.push(pair<long long, int>(distance[v], v));
		}
		
		// ダイクストラ開始
		// Qが空になるまで
		while(Q.empty() == false) {
			// Qの中で一番距離が小さい点uを取り出す
			u = Q.top().second;
			Q.pop();

			// uから行けるvについて処理する
			for(auto v : G[u]) {
				if(distance[v.first] > distance[u] + v.second) {
					distance[v.first] = distance[u] + v.second;
					// 距離の小さい方から取り出すために負にしてQに記録
					Q.push(pair<long long, int>(-distance[v.first], v.first));
				}
			}
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




// 木
struct Tree {
    vector<vector<int>> children;
    vector<int> depth;
    vector<int> parent;
    
    Tree(int N) { 
        children.assign(N, vector<int>{});
        depth.assign(N, -1);
        parent.assign(N, -1);
    }

    // 子要素を追加
    void add_child(int u, int v) {
        children[u].push_back(v);
        parent[v] = u;
    }

    // BFSで深さを計算
    void calc_depth() {
        int root;

        // 根を求める
        for (int i = 0; i < n; i++) {
            if (parent[i] == -1) {
                root = i;
                break;
            }
        }

        queue<int> node;
        int u;

        depth[root] = 0;
        node.push(root);

        while (node.empty() == false) {
            u = node.front();
            node.pop();

            // u から行ける各頂点 v について再帰的に探索
            for (auto v : children[u]) { 
                if (depth[v] == -1) {
                    depth[v] = depth[u] + 1;
                    node.push(v);
                }
            }           
        }
    }

    // 要素の種類を判定
    string kind(int node) {
        if (parent[node] == -1) {
            return "root";
        } else if (children[node].empty() == true) {
            return "leaf";
        } else {
            return "internal node";
        }
    }
};




// 二分木構造
struct BinaryTree {
    vector<pair<int, int>> children;
    vector<int> depth;
    vector<int> height;
    vector<int> parent;
    
    BinaryTree(int N) { 
        children.assign(N, make_pair(-1, -1));
        depth.assign(N, -1);
        height.assign(N, -1);
        parent.assign(N, -1);
    }

    // 子要素を追加
    void add_child(int u, int v1, int v2) {
        children[u] = make_pair(v1, v2);
        if (v1 != -1) {
            parent[v1] = u;   
        }

        if (v2 != -1) {
            parent[v2] = u;   
        }
    }

    // BFSで深さを計算
    void calc_depth() {
        int root;

        // 根を求める
        for (int i = 0; i < n; i++) {
            if (parent[i] == -1) {
                root = i;
                break;
            }
        }

        queue<int> node;
        int u, v1, v2;

        depth[root] = 0;
        node.push(root);

        while (node.empty() == false) {
            u = node.front();
            node.pop();

            // u から行ける各頂点 v について再帰的に探索
            v1 = children[u].first;
            if (depth[v1] == -1) {
                depth[v1] = depth[u] + 1;
                node.push(v1);
            }           
            v2 = children[u].second;
            if (depth[v2] == -1) {
                depth[v2] = depth[u] + 1;
                node.push(v2);
            }  
        }
    }

    // BFSで高さを計算
    void calc_height() {
        for (int i = 0; i < n; i++) {
            if (children[i].first == -1) {
                queue<int> node;
                int u, v;

                height[i] = 0;
                node.push(i);

                while (node.empty() == false) {
                    u = node.front();
                    node.pop();

                    // u から行ける各頂点 v について再帰的に探索
                    v = parent[u];

                    if (v == -1) {
                        break;
                    }
                    height[v] = max(height[v], height[u] + 1);
                    node.push(v);         
                }
            }
        }       
    }

    // 要素の種類を判定
    string type(int node) {
        if (parent[node] == -1) {
            return "root";
        } else if (children[node].first == -1 && children[node].second == -1) {
            return "leaf";
        } else {
            return "internal node";
        }
    }

    int sibling(int node) {
        if (parent[node] == -1) {
            return -1;
        }

        int i1 = children[parent[node]].first;
        int i2 = children[parent[node]].second;

        if (i1 == node) {
            return i2;
        } 
        
        return i1;
    }

    int degree(int node) {
        if (children[node].first == -1 && children[node].second == -1) {
            return 0;
        }
        if (children[node].first != -1 && children[node].second != -1) {
            return 2;
        }

        return 1;
    }

    void Preorder(int s) {
        if (s == -1) {
            return;
        }
 
        cout << " " << s;
        Preorder(children[s].first);
        Preorder(children[s].second);  
    }

    void Inorder(int s) {
        if (s == -1) {
            return;
        }
 
        Inorder(children[s].first);
        cout << " " << s;
        Inorder(children[s].second);  
    }

    void Postorder(int s) {
        if (s == -1) {
            return;
        }
 
        Postorder(children[s].first);
        Postorder(children[s].second); 
        cout << " " << s;
    }
};



// ノード型
struct Node {
    int key;
    Node *parent, *left, *right;

    Node() {
        parent = NULL, left = NULL, right = NULL;
    }

};


// 二分探索木
struct BinarySearchTree {
    Node *root;
    
    BinarySearchTree() { 
        root = NULL;
    }

    // 要素の挿入
    void insert(int num) {
        Node *x, *y, *z;
        z = new Node;
        z->key = num;
        y = NULL;
        x = root;

        while (x != NULL) {
            y = x;
            if (z->key < x->key) {
                x = x->left;
            } else {
                x = x->right;
            }
        }

        z->parent = y;

        if (y == NULL) {
            root = z;
        } else if (z->key < y->key) {
            y->left = z;
        } else {
            y->right = z;
        }
    }

    // 要素の検索
    bool find(int num) {
        Node *tmp = root;
        
        while (tmp != NULL) {
            if (tmp->key == num) {
                return true;
            }

            if (tmp->key > num) {
                tmp = tmp->left;
            } else {
                tmp = tmp->right;
            }
        }

        return false;
    }

    // 要素の削除
    void delete_(int num) {
        Node *tmp = root;
        Node *z;
        
        while (tmp != NULL) {
            if (tmp->key == num) {
                z = tmp;
                
                // zの左の子がNULLの場合
                if (z->left == NULL) {
                    Replace(z, z->right);
                // zの右の子がNULLの場合
                } else if (z->right == NULL) {
                    Replace(z, z->left);                  
                // zの両方の子が非NULLの場合(2つの子を持つ場合)
                } else {
                    Node *y = min_node(z->right);
                    z->key = y->key;

                    // yの左の子がNULLの場合
                    if (y->left == NULL) {
                        Replace(y, y->right);
                    // yの右の子がNULLの場合
                    } else if (y->right == NULL) {
                        Replace(y, y->left);
                    }
                }

                break;
            }

            if (tmp->key > num) {
                tmp = tmp->left;
            } else {
                tmp = tmp->right;
            }
        }
    }

    // ノードnをmに置き換える
    void Replace(Node *n, Node *m) {
        Node *p = n->parent;
        if (m != NULL) {
            m->parent = p;
        }

        // nが根のとき
        if (n == root) {
            root = m;
        // nがpの左の子のとき
        } else if (p->left == n) {
            p->left = m;
        // nがpの右の子のとき
        } else {
            p->right = m;
        }
    }

    // 根sの部分木の一番左の(最小)ノードを返す
    Node *min_node(Node *s) {
        Node *tmp = s;
        while (tmp->left != NULL) {
            tmp = tmp->left;
        }

        return tmp;
    } 

    void print() {
        Inorder(root);
        cout << endl;
        Preorder(root);
        cout << endl;
    }

    void Preorder(Node *s) {
        if (s == NULL) {
            return;
        }
 
        cout << " " << s->key;
        Preorder(s->left);
        Preorder(s->right);
    }

    void Inorder(Node *s) {
        if (s == NULL) {
            return;
        }
 
        Inorder(s->left);
        cout << " " << s->key;
        Inorder(s->right);  
    }

    void Postorder(Node *s) {
        if (s == NULL) {
            return;
        }
 
        Postorder(s->left);
        Postorder(s->right); 
        cout << " " << s->key;
    }
};




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



    // おつりの枚数計算
    vector<int> coins = {25, 10, 5, 1};

    // 初期値
    int tmp = n;

    for (auto coin : coins) {
        answer += tmp / coin;
        tmp -= coin * (tmp / coin);
    }


    // 区間スケジューリング
    // 終端、始端の順で格納
    vector<pair<int, int>> activities(n);

    for (int i = 0; i < n; i++) {
        cin >> activities[i].second >> activities[i].first;
    }

    // 区間の終端でソート
    sort(activities.begin(), activities.end());

    // 現在の終端
    int current_end = 0;
    int answer = 0;

    for (int i = 0; i < n; i++) {
        // 現在の終端より見ている始端が大きければ現在の終端を見ている終端で更新
        if (activities[i].second > current_end) {
            answer++;
            current_end = activities[i].first;
        }
    }


// シンプルな文字列検索
bool simple_search(string S, string T) {
	int len_S = S.size(), len_T = T.size();

	for (int i = 0; i < len_S - len_T + 1; i++) {
		bool flag = true;

		for (int k = 0; k < len_T; k++) {
			if (S[i+k] != T[k]) {
				flag = false;
				break;
			}
		}

		if (flag == true) {
			return true;
		}
	}

	return false;
}



// KMP法
// KMP法のtableを返す
vector<int> KMP_table(string W) {
    // tableの中で現在計算している位置
    int i = 2;
    // 現在見ている部分文字列の次の文字の位置
    int j = 0;

    vector<int> table(W.size());

    table[0] = -1, table[1] = 0;

    while (i < W.size()) {
        if (W[i-1] == W[j]) {
            table[i] = j+1;
            i++, j++;
        } else if (j > 0) {
            j = table[j];
        } else {
            table[i] = 0;
            i++;
        }
    }

    return table;
}


// 文字列Sから文字列Wを検索するKMP法
void KMP_search(string S, string W) {
    // Sの現在検索中の開始位置
    int m = 0;
    // Wの現在位置
    int i = 0;

    vector<int> table = KMP_table(W);

    while (m+i < S.size()) {
        if (W[i] == S[m+i]) {
            i++;

            if (i == W.size()) {
                cout << m << endl;
                // 続けて出力する場合は以下も加える
                i = 0;
                m = m+i - table[i];
            }
        } else {
            m = m+i - table[i];

            if (i > 0) {
                i = table[i];
            }
        }
    }  
}


// BM法
// BM法のずらし表を返す
vector<int> BM_table(string W) {
    vector<int> table(128, W.size());
    int W_len = W.size();

    for (int i = 0; i < W_len; i++) {
        table[(int)W[i]] = min(table[(int)W[i]], W_len - 1 - i);
    }

    return table;
}


// 文字列Sから文字列Wを検索するBM法
void BM_search(string S, string W) {
    int W_len = W.size();

    // Sの現在検索中の位置
    int i = W_len-1;
    // Wの現在検索中の位置
    int j = W_len-1;

    vector<int> table = BM_table(W);

    while (i < S.size()) {
        // 文字列が一致する間
        while (W[j] == S[i]) {
            // 全てが一致したとき出力
            if (j == 0) {
                cout << i << endl;
                break;
            } 

            i--, j--;
        }

        // iを次の位置に動かし、jをリセット
        i += max(W_len - j, table[(int)S[i]]);
        j = W_len - 1;
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



// 最大公約数
long long GCD(long long a, long long b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}

// 最小公倍数
long long LCM(long long x, long long y) {
	return x * y / GCD(x, y);
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
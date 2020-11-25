#include<bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>> &graph, vector<int> &counter, int child, int parent = 0) {
    for(int son : graph[child]) {
        if(son == parent) {
            continue;
        }

        counter[son] += counter[child];
        dfs(graph, counter, son, child);
    }
}

int main() {
	int N, Q;
    cin >> N >> Q;

    vector<int> a(N), b(N);
    vector<int> p(Q), x(Q);

    vector<int> counter(N+1, 0);
    vector<vector<int>> graph(N+1, vector<int>{});

    for(int i = 0; i < N-1; i++) {
        cin >> a[i] >> b[i];
        graph[a[i]].push_back(b[i]);
        graph[b[i]].push_back(a[i]);
    }

    for(int i = 0; i < Q; i++) {
        cin >> p[i] >> x[i];
        counter[p[i]] += x[i];
    }

    dfs(graph, counter, 1);

    for(int i = 1; i <= N; i++) {
        cout << counter[i] << " ";
    }

	return 0;
}
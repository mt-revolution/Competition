#include<bits/stdc++.h>

using namespace std;

int N,M,Q;
vector<int> a,b,c,d;
int answer = 0;

// 広義単調増加列を作る
void dfs(vector<int> A) {
	// 終了条件
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

	// 末尾に要素を追加
	A.push_back(A.back());
	while (A.back() <= M) {
		dfs(A);
		A.back()++;
	}
}


int main() {
	cin >> N >> M >> Q;
	a.assign(Q, 0);
	b.assign(Q, 0);
	c.assign(Q, 0);
	d.assign(Q, 0);

	for (int i = 0; i < Q; i++) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}

	// A[0]はダミー
	dfs(vector<int>(1, 1));
	cout << answer << endl;
	return 0;
}
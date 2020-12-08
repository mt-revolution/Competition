#include<bits/stdc++.h>

using namespace std;


int main() {
	int N,M,Q;
	cin >> N >> M >> Q;
	
	int t,n,m;
	// 問題ごとの点数
	vector<int> score(M, N);
	// それぞれの人が解いた問題
	vector<vector<int>> player(N, vector<int>{});
	int count = 0;
	
	for (int i = 0; i < Q; i++) {
		cin >> t;
		
		if (t == 1) {
			cin >> n;
			n--;

			count = 0;

			// 解いた問題の現在の点数を加算
			for (auto question : player[n]) {
				count += score[question];
			}

			cout << count << endl;	
		} else {
			cin >> n >> m;
			n--, m--;

			// 解いた問題に加えてその問題の点数を1点減らす
			player[n].push_back(m);
			score[m]--;
		}
	}
	return 0;
}
#include<bits/stdc++.h>

using namespace std;


int main() {
	queue<pair<char, long long>> S;
	
	int Q;
	cin >> Q;
	
	long long T, X, D;
	char C;

	pair<char, long long> tmp;
	long long answer = 0;

	for (int i = 0; i < Q; i++) {
		cin >> T;
		
		if (T == 1) {
			cin >> C >> X;
			S.push(make_pair(C, X));
		} else {
			cin >> D;
			answer = 0;

			vector<long long> count(26, 0);

			// Dが0になるまで、またはSが空になるまで操作を続ける
			while (D > 0 && S.empty() == false) {
				tmp = S.front();

				// 先頭がD以下の場合先頭を削除
				if (tmp.second <= D) {
					S.pop();
					D -= tmp.second;
					count[tmp.first - 'a'] += tmp.second;
				// 先頭がDより大きい場合先頭の値を操作
				} else {
					S.front().second -= D;
					count[tmp.first - 'a'] += D;
					D = 0;
				}
			}

			for (auto num : count) {
				answer += num * num;
			}

			cout << answer << endl;
		}
	}
	return 0;
}
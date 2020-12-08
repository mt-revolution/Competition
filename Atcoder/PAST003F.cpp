#include<bits/stdc++.h>

using namespace std;


int main() {
	int N;
	cin >> N;
	
	char a;
	// 各行にそれぞれのアルファベットが含まれているか管理
	vector<vector<int>> id(N, vector<int>(26, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> a;
			id[i][a - 'a']++;
		}
	}

	string S(N, 'E');
	int j;
	bool flag;

	for (int i = 0; i < N; i++) {
		// 回文のペアのインデックス
		j = N-1-i;

		if (j < i) {
			break;
		}

		// Nが奇数でjとiが等しくなったとき
		if (j == i) {
			flag = false;
			for (int k = 0; k < 26; k++) {
				if (id[i][k] != 0 && id[j][k] != 0) {
					S[i] = (char)('a' + k);
					flag = true;
					break;
				}
			}

		} else {
			flag = false;
			for (int k = 0; k < 26; k++) {
				if (id[i][k] != 0 && id[j][k] != 0) {
					S[i] = (char)('a' + k);
					S[j] = (char)('a' + k);
					flag = true;
					break;
				}
			}
		}

		// 一致する文字がなかった場合回文は作れない
		if (flag == false) {
			cout << -1 << endl;
			return 0;
		}
	}

	cout << S << endl;
	return 0;
}
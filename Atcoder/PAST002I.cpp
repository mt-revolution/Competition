#include<bits/stdc++.h>

using namespace std;


int main() {
	int N;
	cin >> N;

	vector<pair<int, int>> A(1<<N);
	vector<int> last_fight(1<<N, 1);

	int strength;
	
	for (int i = 0; i < (1<<N); i++) {
		cin >> strength;
		A[i] = make_pair(i, strength);
	}
	
	// 勝者の結果の配列を更新しながら最終ラウンドの1つ前まで繰り返す
	for (int i = N; i >= 2; i--) {
		vector<pair<int, int>> A_tmp;
		
		for (int j = 0; j < (1<<(i-1)); j++) {
			if (A[2*j].second > A[2*j+1].second) {
				last_fight[A[2*j].first]++;
				A_tmp.push_back(A[2*j]);
			} else {
				last_fight[A[2*j+1].first]++;
				A_tmp.push_back(A[2*j+1]);
			}
		}

		A = A_tmp;
	}

	for (int i = 0; i < (1<<N); i++) {
		cout << last_fight[i] << endl;
	}
	return 0;
}
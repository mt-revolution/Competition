#include<bits/stdc++.h>

using namespace std;


int main() {
	long long N,Q;
	cin >> N >> Q;
	
	vector<int> row(N), column(N);

	// 行と列の順列をそれぞれ作っておく
	for (int i = 0; i < N; i++) {
		row[i] = i, column[i] = i;
	}

	// 転置状態なら1、普通なら0
	int T_mode = 0;

	int T,A,B;
	long long answer;

	// 各クエリについて転置状態とそうでない状態でわけて処理
	for (int i = 0; i < Q; i++) {
		cin >> T;
		
		if (T == 1) {
			cin >> A >> B;
			A--, B--;
			
			if (T_mode == 0) {
				swap(row[A], row[B]);
			} else {
				swap(column[A], column[B]);
			}
		} else if (T == 2) {
			cin >> A >> B;
			A--, B--;

			if (T_mode == 0) {
				swap(column[A], column[B]);
			} else {
				swap(row[A], row[B]);
			}
			
		} else if (T == 3) {
			T_mode = 1 - T_mode;
			
		} else if (T == 4) {
			cin >> A >> B;
			A--, B--;

			if (T_mode == 0) {
				answer = N*(row[A]) + column[B];
			} else {
				answer = N*(row[B]) + column[A];
			}

			cout << answer << endl;
		}
	}
	
	return 0;
}
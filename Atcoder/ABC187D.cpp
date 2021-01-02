#include<bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin >> N;
	
	// 2*A+B、A+B、Aの順のタプルの配列
	vector<tuple<long long, long long, long long>> tmp(N);
	long long A,B;
	long long sum_T = 0, sum_A = 0;

	for (int i = 0; i < N; i++) {
		cin >> A >> B;
		tmp[i] = make_tuple(2*A+B, A+B, A);
		sum_A += A;
	}

	// 2*A+Bで降順ソート
	sort(tmp.rbegin(), tmp.rend());

	// 先頭から順番に高橋氏の票数が青木氏の票数を上回るまでカウント
	for (int i = 0; i < N; i++) {
		sum_A -= get<2>(tmp[i]);
		sum_T += get<1>(tmp[i]);

		if (sum_T > sum_A) {
			cout << i+1 << endl;
			break;
		}
	}
	
	return 0;
}
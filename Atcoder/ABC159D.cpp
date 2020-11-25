#include<bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin >> N;
	
	vector<int> A(N);
	// それぞれの数のカウントとその組み合わせ数
	vector<long long> count(N+1, 0), comb(N+1, 0);

	// それぞれの数をカウント
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		count[A[i]]++;
	}

	long long sum = 0;
	
	// 組み合わせ数とその和を計算
	for (int i = 1; i <= N; i++) {
		comb[i] = count[i] * (count[i]-1) / 2; 
		sum += comb[i];
	}

	long long answer = 0;

	// それぞれの数の組み合わせの数を和から引いて新しい組み合わせの数を足す
	for (int i = 0; i < N; i++) {
		answer = sum - comb[A[i]] + (count[A[i]]-1) * (count[A[i]]-2) / 2;
		cout << answer << endl;
	}

	return 0;
}
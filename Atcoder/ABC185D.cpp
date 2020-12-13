#include<bits/stdc++.h>

using namespace std;

int main() {
	int N,M;
	cin >> N >> M;

	vector<int> A(M+2);

	A[0] = 0;
	A[M+1] = N+1;

	for (int i = 1; i <= M; i++) {
		cin >> A[i];
	}

	// ソートしておく
	sort(A.begin()+1, A.end()-1);

	if (N == M) {
		cout << 0 << endl;
		return 0;
	}

	if (M == 0) {
		cout << 1 << endl;
		return 0;
	}
	
	int k = 2000000000;

	// kは区間幅の最小値
	for (int i = 1; i <= M+1; i++) {
		if (A[i] - A[i-1] - 1 >= 1) {
			k = min(k, A[i] - A[i-1] - 1);
		}
	}

	int answer = 0;

	for (int i = 1; i <= M+1; i++) {
		if (A[i] - A[i-1] - 1 >= 1) {
			if ((A[i] - A[i-1] - 1) % k == 0) {
				answer += (A[i] - A[i-1] - 1) / k;
			} else {
				answer += (A[i] - A[i-1] - 1) / k + 1;
			}
		}
	}

	cout << answer << endl;
	return 0;
}
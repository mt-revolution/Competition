#include<bits/stdc++.h>

using namespace std;


int main() {
	int N;
	cin >> N;
	
	vector<int> A(N+1);
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	int tmp, count;

	for (int i = 1; i <= N; i++) {
		tmp = i;
		count = 0;

		// 同じ数に戻ってくるまでループ
		while (1) {
			tmp = A[tmp];
			count++;

			if (tmp == i) {
				if (i == 1) {
					cout << count;
				} else {
					cout << " " << count;
				}
				break;
			}
		}
	}
	return 0;
}
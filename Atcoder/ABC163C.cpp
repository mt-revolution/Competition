#include<bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin >> N;
	
	int A;
	vector<int> sub_num(N, 0);
	for (int i = 0; i < N-1; i++) {
		cin >> A;
		A--;
		sub_num[A]++;
	}

	for (int i = 0; i < N; i++) {
		cout << sub_num[i] << endl;
	}
	return 0;
}
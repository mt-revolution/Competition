#include<bits/stdc++.h>

using namespace std;

int main() {
	string A,B;
	cin >> A >> B;

	int sum_A = 0, sum_B = 0;
	
	for (int i = 0; i < A.size(); i++) {
		sum_A += A[i] - '0';
	}

	for (int i = 0; i < B.size(); i++) {
		sum_B += B[i] - '0';
	}

	cout << max(sum_A, sum_B) << endl;
	return 0;
}
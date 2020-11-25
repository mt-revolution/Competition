#include<bits/stdc++.h>

using namespace std;

int main() {
	int K;
	cin >> K;

	int A,B;
	cin >> A >> B;

	for (int i = A; i <= B; i++) {
		if (i % K == 0) {
			cout << "OK" << endl;
			return 0;
		}
	}

	cout << "NG" << endl;
	return 0;
}
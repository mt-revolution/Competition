#include<bits/stdc++.h>

using namespace std;

int main() {
	int N;
	int sum_alice = 0;
	int sum_bob = 0;
	cin >> N;

	vector<int> a(N);
	for (int i = 0; i < N; i++) {
		cin >> a.at(i);
	}

	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());

	for (int i = 0; i < N; i++) {
		if (i % 2 == 0) {
			sum_alice += a.at(i);
		}
		else {
			sum_bob += a.at(i);
		}
	}

	cout << sum_alice - sum_bob << endl;
	return 0;
}
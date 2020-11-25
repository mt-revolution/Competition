#include<bits/stdc++.h>

using namespace std;


int main() {
	vector<long long> cookie(4);
	for (int i = 0; i < 4; i++) {
		cin >> cookie[i];
	}

	long long sum_1 = 0, sum_2 = 0;

	for (int biti = 1; biti < (1<<4); biti++) {
		sum_1 = 0, sum_2 = 0;

		for (int i = 0; i < 4; i++) {
			if (biti & (1<<i)) {
				sum_1 += cookie[i];
			} else {
				sum_2 += cookie[i];
			}
		}

		if (sum_1 == sum_2) {
			cout << "Yes" << endl;
			return 0;
		}
	}

	cout << "No" << endl;
	return 0;
}
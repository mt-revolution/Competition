#include<bits/stdc++.h>

using namespace std;

int main() {
	int K;
	cin >> K;

	vector<int> a(1000001);
	int answer = -1;

	a[1] = 7 % K;
	if (a[1] == 0) {
		cout << 1 << endl;
		return 0;
	}

	for (int i = 2; i <= 1000000; i++) {
		a[i] = (a[i-1] * 10 + 7) % K;
		if (a[i] == 0) {
			answer = i;
			break;
		}
	}

	cout << answer << endl;
	return 0;
}
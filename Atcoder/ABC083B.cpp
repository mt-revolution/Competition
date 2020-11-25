#include<bits/stdc++.h>

using namespace std;

int main() {
	int n, a, b;
	int temp;
	int sum = 0;
	int answer = 0;
	cin >> n >> a >> b;

	for (int i = 1; i <= n; i++) {
		sum = 0;
		temp = i;

		while (1) {
			if (temp <= 9) {
				sum += temp;
				break;
			}
			else {
				sum += temp % 10;
				temp /= 10;
			}
		}

		if (sum >= a && sum <= b) {
			answer += i;
		}
	}

	cout << answer << endl;
	return 0;
}
#include<bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin >> N;

	long long answer = 0;
	
	for (int i = 1; i <= N; i++) {
		if (i % 5 != 0 && i % 3 != 0) {
			answer += i;
		}
	}

	cout << answer << endl;
	return 0;
}
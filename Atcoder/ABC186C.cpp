#include<bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin >> N;

	int tmp, digit;
	bool flag;
	int answer = N;
	
	for (int i = 1; i <= N; i++) {
		tmp = i;
		flag = true;

		// 10進法で7が含まれているか調べる
		while (tmp > 0) {
			digit = tmp % 10;
			tmp /= 10;
			if (digit == 7) {
				flag = false;
				break;
			}
		}

		tmp = i;

		// 8進法で7が含まれているか調べる
		while (tmp > 0) {
			digit = tmp % 8;
			tmp /= 8;
			if (digit == 7) {
				flag = false;
				break;
			}
		}

		if (flag == false) {
			answer--;
		}
	}

	cout << answer << endl;
	return 0;
}
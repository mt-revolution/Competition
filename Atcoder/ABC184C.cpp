#include<bits/stdc++.h>

using namespace std;

int main() {
	long long r_1, c_1, r_2, c_2;
	cin >> r_1 >> c_1 >> r_2 >> c_2;

	long long answer;
	
	if (r_1 == r_2 && c_1 == c_2) {
		cout << 0 << endl;
		return 0;
	}

	if (r_1 + c_1 == r_2 + c_2 || r_1 - c_1 == r_2 - c_2 || abs(r_1 - r_2) + abs(c_1 - c_2) <= 3) {
		cout << 1 << endl;
		return 0;
	}

	if ((r_1 + c_1 + r_2 + c_2) % 2 == 0 || abs(r_1 - c_1) + abs(r_2 - c_2) <= 6 || abs(r_1 + c_1 - (r_2 + c_2)) <= 3 || abs(r_1 - c_1 - (r_2 - c_2)) <= 3) {
		cout << 2 << endl;
		return 0;
	}

	cout << 3 << endl;
	return 0;
}
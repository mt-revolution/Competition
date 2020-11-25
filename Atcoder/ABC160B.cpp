#include<bits/stdc++.h>

using namespace std;

int main() {
	long long X;
	cin >> X;
	
	long long coin_500 = X / 500;
	X -= 500 * coin_500;
	long long coin_5 = X / 5;

	long long answer = 1000 * coin_500 + 5 * coin_5;

	cout << answer << endl;
	return 0;
}
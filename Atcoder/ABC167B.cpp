#include<bits/stdc++.h>

using namespace std;

int main() {
	int A,B,C,K;
	cin >> A >> B >> C >> K;

	int answer = 0;
	int x;

	x = min(K, A);
	answer += x;
	K -= x;

	x = min(K, B);
	K -= x;

	x = min(K, C);
	answer -= x;
	K -= x;

	cout << answer << endl;
	return 0;
}
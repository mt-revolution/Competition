#include<bits/stdc++.h>

using namespace std;

long long MOD = 998244353;

int main() {
	long long A,B,C;
	cin >> A >> B >> C;

	long long answer = 1;
	long long part_a = (A*(A+1)/2) % MOD;
	long long part_b = (B*(B+1)/2) % MOD;
	long long part_c = (C*(C+1)/2) % MOD;
	answer = (answer * part_a) % MOD;
	answer = (answer * part_b) % MOD;
	answer = (answer * part_c) % MOD;
	
	cout << answer << endl;
	return 0;
}
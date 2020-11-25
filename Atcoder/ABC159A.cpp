#include<bits/stdc++.h>

using namespace std;

int main() {
	int N,M;
	cin >> N >> M;
	
	int answer = N*(N-1)/2 + M*(M-1)/2;
	cout << answer << endl;
	return 0;
}
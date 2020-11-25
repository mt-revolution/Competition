#include<bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin >> N;
	
	set<string> goods;
	string S;

	for (int i = 0; i < N; i++) {
		cin >> S;
		goods.insert(S);
	}

	int answer = goods.size();

	cout << answer << endl;
	return 0;
}
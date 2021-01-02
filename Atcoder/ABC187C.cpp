#include<bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin >> N;

	string S;
	map<string, pair<int, int>> A;

	for (int i = 0; i < N; i++) {
		cin >> S;
		if (S[0] == '!') {
			A[S.substr(1, S.size()-1)].first += 1;
		} else {
			A[S].second += 1;
		}
	}

	for (auto iter = A.begin(); iter != A.end(); iter++) {
		if (iter -> second.first >= 1 && iter -> second.second >= 1) {
			cout << iter -> first << endl;
			return 0;
		}
	}

	cout << "satisfiable" << endl;
	return 0;
}
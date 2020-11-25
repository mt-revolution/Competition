#include<bits/stdc++.h>

using namespace std;

int main() {
	int X, N;
	int min_abs = 100;
	int answer;
	int tmp;
	cin >> X >> N;

	set<int> p;
	vector<int> rest;

	for (int i = 0; i < N; i++) {
		cin >> tmp;
		p.insert(tmp);
	}

	rest.push_back(0);
	for (int i = 1; i <= 100; i++) {
		if (p.count(i) == false) {
			rest.push_back(i);
		}
	}

	rest.push_back(101);


	for (int i : rest) {
		if (abs(i - X) < min_abs) {
			min_abs = abs(i - X);
			answer = i;
		}
	}

	cout << answer << endl;
	return 0;
}
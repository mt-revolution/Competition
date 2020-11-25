#include<bits/stdc++.h>

using namespace std;

int main() {
	int N;
	vector<int> x(5);
	for (int i = 0; i < 5; i++) {
		cin >> x.at(i);
	}

	for (int i = 0; i < 5; i++) {
		if (x.at(i) == 0) {
			cout << i+1 << endl;
		}
	}
	return 0;
}
#include<bits/stdc++.h>

using namespace std;

int main() {
	int N;
	int num;
	cin >> N;

	set<int> d;
	for (int i = 0; i < N; i++) {
		cin >> num;
		d.insert(num);
	}

	cout << d.size() << endl;
	return 0;
}
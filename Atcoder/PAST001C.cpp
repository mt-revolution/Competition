#include<bits/stdc++.h>

using namespace std;

int main() {
	vector<int> num(6);
	for (int i = 0; i < 6; i++) {
		cin >> num[i];
	}

	sort(num.begin(), num.end());
	cout << num[3] << endl;
	return 0;
}
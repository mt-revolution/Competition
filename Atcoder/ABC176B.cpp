#include<bits/stdc++.h>

using namespace std;

int main() {
	string N;
	cin >> N;

	int N_size = N.size();

	int sum = 0;

	for(int i = 0; i < N_size; i++) {
		sum += N[i] - '0';
	}

	if(sum % 9 == 0) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	return 0;
}


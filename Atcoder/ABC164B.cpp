#include<bits/stdc++.h>

using namespace std;

int main() {
	int A,B,C,D;
	cin >> A >> B >> C >> D;
	
	while (1) {
		C -= B;
		if (C <= 0) {
			cout << "Yes" << endl;
			return 0;
		}

		A -= D;
		if (A <= 0) {
			cout << "No" << endl;
			return 0;
		}
	}
	return 0;
}
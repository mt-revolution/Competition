#include<bits/stdc++.h>

using namespace std;

int main() {
	int X;
	cin >> X;

	int result;

	if(X >= 400 && X <= 599) {
		result = 8;
	} else if(X >= 600 && X <= 799) {
		result = 7;
	} else if(X >= 800 && X <= 999) {
		result = 6;
	} else if(X >= 1000 && X <= 1199) {
		result = 5;
	} else if(X >= 1200 && X <= 1399) {
		result = 4;
	} else if(X >= 1400 && X <= 1599) {
		result = 3;
	} else if(X >= 1600 && X <= 1799) {
		result = 2;
	} else {
		result = 1;
	}

	cout << result << endl;
	return 0;
}
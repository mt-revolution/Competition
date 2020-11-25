#include<bits/stdc++.h>

using namespace std;

int main() {
	int A, B, C, K;
	cin >> A >> B >> C;
	cin >> K;

	string result = "No";

	for(int i = 0; i <= K; i++) {
		if(B <= A) {
			B *= 2;
		} else if(C <= A) {
			C *= 2;
		} else if(C <= B) {
			C *= 2;
		
		} else {
			result = "Yes";
			break;
		}
	}

	cout << result << endl;
	return 0;
}
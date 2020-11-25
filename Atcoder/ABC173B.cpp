#include<bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<string> S(N);
	vector<int> C(4, 0);

	for(int i = 0; i < N; i++) {
		cin >> S.at(i);
	}

	for(int i = 0; i < N; i++) {
		if(S.at(i) == "AC") {
			C[0] += 1;
		} else if(S.at(i) == "WA") {
			C[1] += 1;
		} else if(S.at(i) == "TLE") {
			C[2] += 1;					
		} else if(S.at(i) == "RE") {
			C[3] += 1;			
		}

	}

	cout << "AC x " << C[0] << endl;
	cout << "WA x " << C[1] << endl;
	cout << "TLE x " << C[2] << endl;
	cout << "RE x " << C[3] << endl;
	return 0;
}
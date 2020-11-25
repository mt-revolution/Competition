#include<bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> x(N), y(N);
	for (int i = 0; i < N; i++) {
		cin >> x[i] >> y[i];
	}

	for (int i = 0; i < N-2; i++) {
		for (int j = i+1; j < N-1; j++) {
			for (int k = j+1; k < N; k++) {
				if ((y[k]-y[i]) * (x[j]-x[i]) == (y[j]-y[i]) * (x[k]-x[i])) {
					cout << "Yes" << endl;
					return 0;
				}
			}
		}
	}
	
	cout << "No" << endl;
	return 0;
}
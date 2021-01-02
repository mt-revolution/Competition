#include<bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin >> N;
	
	vector<double> x(N), y(N);
	for (int i = 0; i < N; i++) {
		cin >> x[i] >> y[i];
	}

	int count = 0;
	
	for (int i = 0; i < N-1; i++) {
		for (int j = i+1; j < N; j++) {
			if ((y[j] - y[i]) / (x[j] - x[i]) >= -1 && (y[j] - y[i]) / (x[j] - x[i]) <= 1) {
				count++;
			}
		}
	}

	cout << count << endl;
	return 0;
}
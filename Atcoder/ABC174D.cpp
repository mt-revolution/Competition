#include<bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<char> c(N);
	int count = 0;

	for(int i = 0; i < N; i++) {
		cin >> c[i];
	}

	int i = 0, j = N-1;

	while(i <= j) {
		if(c[i] == 'W') {
			if(c[j] == 'R') {				
				swap(c[i], c[j]);				
				count++;
				i++;
				j--;
			} else {
				j--;
			}
		} else {
			i++;
		}
	}

	cout << count << endl;
	return 0;
}
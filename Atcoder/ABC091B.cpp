#include<bits/stdc++.h>

using namespace std;


int main() {
	int N, M;
	int count = 0;
	int count_max = -100;
	string search_word;

	cin >> N;

	vector<string> s(N);
	for (int i = 0; i < N; i++) {
		cin >> s.at(i);
	}

	cin >> M;

	vector<string> t(M);
	for (int i = 0; i < M; i++) {
		cin >> t.at(i);
	}

	for (int i = 0; i < N; i++) {
		count = 0;
		search_word = s.at(i);

		for (int j = 0; j < N; j++) {
			if (s.at(j) == search_word) {
				count++;
			}
		}

		for (int j = 0; j < M; j++) {
			if (t.at(j) == search_word) {
				count--;
			}
		}

		if (count > count_max) {
			count_max = count;
		}
	}

	if (count_max < 0) {
		count_max = 0;
	}

	cout << count_max << endl;
	
	return 0;
}
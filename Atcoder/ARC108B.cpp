#include<bits/stdc++.h>

using namespace std;


int main() {
	int N;
	cin >> N;
	
	string s;
	cin >> s;

	vector<char> tmp;
	int tmp_size;

	int answer = N;

	for (int i = 0; i < N; i++) {
		tmp.push_back(s[i]);
		tmp_size = tmp.size();

		if (i >= 2) {
			if (tmp[tmp_size-3] == 'f' && tmp[tmp_size-2] == 'o' && tmp[tmp_size-1] == 'x') {
				tmp.erase(tmp.begin() + (tmp_size-3), tmp.end());
				answer -= 3;
			}
		}
	}

	cout << answer << endl;
	return 0;
}
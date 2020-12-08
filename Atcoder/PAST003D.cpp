#include<bits/stdc++.h>

using namespace std;

// それぞれの数字の表示の仕方を見ながら地道に実装
string translate(vector<string> s, int i) {
	if (s[1][4*i-2] == '#' && s[3][4*i-2] == '#') {
		return "1";
	}

	if (s[1][4*i-3] == '#' && s[1][4*i-1] == '#' && s[3][4*i-3] == '#' && s[3][4*i-1] == '#') {
		if (s[2][4*i-2] == '#') {
			return "8";
		} else {
			return "0";
		}
	}

	if (s[3][4*i-3] == '#' && s[3][4*i-1] == '#') {
		return "6";
	}

	if (s[0][4*i-1] == '#' && s[1][4*i-1] == '#' && s[2][4*i-1] == '#' && s[3][4*i-1] == '#' && s[4][4*i-1] == '#') {
		if (s[0][4*i-2] == '#' && s[2][4*i-2] == '#' && s[4][4*i-2] == '#') {
			if (s[1][4*i-3] == '#') {
				return "9";
			} else {
				return "3";
			}
		} else {
			if (s[1][4*i-3] == '#') {
				return "4";
			} else {
				return "7";
			}
		}
	}

	if (s[1][4*i-3] == '#') {
		return "5";
	} else {
		return "2";
	}
}


int main() {
	int N;
	cin >> N;
	
	vector<string> s(5);

	for (int i = 0; i < 5; i++) {
		cin >> s[i];
	}

	string answer = "";

	for (int i = 1; i <= N; i++) {
		answer += translate(s, i);
	}

	cout << answer << endl;
	return 0;
}
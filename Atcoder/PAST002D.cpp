#include<bits/stdc++.h>

using namespace std;

// シンプルな文字列検索
bool simple_search(string S, string T) {
	int len_S = S.size(), len_T = T.size();

	for (int i = 0; i < len_S - len_T + 1; i++) {
		bool flag = true;

		for (int k = 0; k < len_T; k++) {
			if (T[k] == '.') {
				continue;
			}

			if (S[i+k] != T[k]) {
				flag = false;
				break;
			}
		}

		if (flag == true) {
			return true;
		}
	}

	return false;
}


int main() {
	string S;
	cin >> S;

	int len_S = S.size();
	int answer = 0;

	string T;

	// 1文字、2文字、3文字で全探索
	// 1文字
	for (int i = 0; i < 27; i++) {
		T = "";

		if (i == 26) {
			T += '.';
		} else {
			T += (char)('a'+i);
		}

		if (simple_search(S, T) == true) {
			answer++;
		}
	}

	// 2文字
	for (int i = 0; i < 27; i++) {
		for (int j = 0; j < 27; j++) {
			T = "";

			if (i == 26) {
				T += '.';
			} else {
				T += (char)('a'+i);
			}

			if (j == 26) {
				T += '.';
			} else {
				T += (char)('a'+j);
			}

			if (simple_search(S, T) == true) {
				answer++;
			}
		}
	}
	
	// 3文字
	for (int i = 0; i < 27; i++) {
		for (int j = 0; j < 27; j++) {
			for (int k = 0; k < 27; k++) {
				T = "";

				if (i == 26) {
					T += '.';
				} else {
					T += (char)('a'+i);
				}

				if (j == 26) {
					T += '.';
				} else {
					T += (char)('a'+j);
				}

				if (k == 26) {
					T += '.';
				} else {
					T += (char)('a'+k);
				}

				if (simple_search(S, T) == true) {
					answer++;
				}		
			}
		}
	}

	cout << answer << endl;
	return 0;
}
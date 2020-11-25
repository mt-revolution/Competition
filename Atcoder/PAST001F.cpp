#include<bits/stdc++.h>

using namespace std;

int main() {
	string S;
	cin >> S;

	int S_size = S.size();
	
	vector<string> words;
	string tmp = "";
	int count = 0;

	for (int i = 0; i < S_size; i++) {
		if (S[i] >= 'A' && S[i] <= 'Z') {
			tmp += (S[i] + 32);
			count++;
		} else {
			tmp += S[i];
		}

		if (count == 2) {
			words.push_back(tmp);
			count = 0;
			tmp = "";
		}
	}

	sort(words.begin(), words.end());
	string answer = "";
	int word_size;

	for (auto word : words) {
		word_size = word.size();
		word[0] -= 32;
		word[word_size-1] -= 32;
		answer += word;
	}

	cout << answer << endl;
	return 0;
}
#include<bits/stdc++.h>

using namespace std;


int main() {
	string S;
	cin >> S;
	
	int len_S = S.size();

	vector<int> count(3);

	for (int i = 0; i < len_S; i++) {
		count[S[i] - 'a']++;
	}

	// 要素が最大のインデックスを取得
	int max = max_element(count.begin(), count.end()) - count.begin();
	cout << (char)('a' + max) << endl;
	return 0;
}
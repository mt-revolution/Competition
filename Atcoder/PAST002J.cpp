#include<bits/stdc++.h>

using namespace std;


int main() {
	string S;
	cin >> S;
	
	int len_S = S.size(), len_tmp;
	stack<char> S_answer;

	for (int i = 0; i < len_S; i++) {
		// )が現れるとスタックから(が現れるまで値を取り出し、tmpに格納してtmp+rev(tmp)を新たにスタックに加える
		if (S[i] == ')') {
			string tmp = "";
			
			while (1) {
				if (S_answer.top() == '(') {
					S_answer.pop();
					break;
				}

				tmp += S_answer.top();
				S_answer.pop();
			}

			len_tmp = tmp.size();

			if (len_tmp > 0) {
				for (int j = len_tmp-1; j >= 0; j--) {
					S_answer.push(tmp[j]);
				}
				for (int j = 0; j < len_tmp; j++) {
					S_answer.push(tmp[j]);
				}
			}
		// )以外はスタックに普通に格納
		} else {
			S_answer.push(S[i]);
		}
	}
	
	// 最後にスタックから残っている文字を取り出して逆順で出力する
	string answer = "";
	while (S_answer.empty() == false) {
		answer += S_answer.top();
		S_answer.pop();
	}

	int len_answer = answer.size();

	for (int i = answer.size() - 1; i >= 0; i--) {
		cout << answer[i];
	}
	return 0;
}
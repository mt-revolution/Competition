#include<bits/stdc++.h>

using namespace std;

int main() {
	string S;
    cin >> S;

    for (int biti = 0; biti < (1<<3); biti++) {
        int count = S[0] - '0';

        for (int i = 0; i < 3; i++) {
            // 1なら+、0なら-を表すとする
            if (biti & (1<<i)) {
                count += S[i+1]-'0';
            } else {
                count -= S[i+1]-'0';
            }
        }

        if (count == 7) {
            string answer = "";
            answer += S[0];

            for (int i = 0; i < 3; i++) {
                if (biti & (1<<i)) {
                    answer += '+';
                } else {
                    answer += '-';
                }

                answer += S[i+1];
            }
            
            cout << answer << "=7" << endl;
            return 0;
        }
    }
    
	return 0;
}
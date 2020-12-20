#include<bits/stdc++.h>

using namespace std;

int main() {
	string S;
    cin >> S;

    int len_S = S.size();
    
    vector<int> num(len_S);
    for (int i = 0; i < len_S; i++) {
        num[i] = S[i] - '0';
    }

    long long answer = 0;
    long long count;
    string tmp;

    // +をつけるかつけないかでbit全探索
    for (int biti = 0; biti < (1<<(len_S-1)); biti++) {
        tmp = "";
        count = 0;
        
        for (int i = 0; i < len_S - 1; i++) {
            tmp += S[i];

            // +をつけるとき、それまで記録していた数を足す
            if (biti & (1<<i)) {
                count += stoll(tmp);
                tmp = "";
            }
        }

        // 最後に末尾の数を足す
        tmp += S[len_S-1];
        count += stoll(tmp);

        answer += count;
    }

    cout << answer << endl;
	return 0;
}
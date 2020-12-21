#include<bits/stdc++.h>

using namespace std;

int main() {
	string Sd, T;
    cin >> Sd >> T;
    
    int len_Sd = Sd.size();
    int len_T = T.size();

    bool flag;
    int count;

    // 辞書順最小にするため後方から探索
    for (int i = len_Sd - len_T; i >= 0; i--) {
        flag = true;

        // 文字列Tと一致するか調べる
        for (int j = 0; j < len_T; j++) {
            // ?なら飛ばす
            if (Sd[i+j] == '?') {
                continue;
            }

            // 一致しないなら次の位置で検索
            if (Sd[i+j] != T[j]) {
                flag = false;
                break;
            }
        }

        // 一致した場合
        if (flag == true) {
            for (int j = 0; j < len_T; j++) {
                Sd[i+j] = T[j];
            }

            for (int j = 0; j < len_Sd; j++) {
                if (Sd[j] == '?') {
                    Sd[j] = 'a';
                }
            }

            cout << Sd << endl;
            return 0;
        }
    }

    cout << "UNRESTORABLE" << endl;
	return 0;
}
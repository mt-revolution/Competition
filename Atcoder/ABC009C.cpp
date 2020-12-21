#include<bits/stdc++.h>

using namespace std;

int main() {
    int N,K;
    cin >> N >> K;
    
	string S;
    cin >> S;

    string S_dic = S;
    sort(S_dic.begin(), S_dic.end());
    int min_num;

    // 全ての文字を入れ替えてもいいとき、辞書順に並べ替えて出力
    if (N == K) {
        cout << S_dic << endl;
        return 0;
    } 

    int tmp_K = K;
    string S_dic_tmp = S_dic;
    string answer = "";

    for (int i = 0; i < N; i++) {
        // i+1から末尾までの元の文字列の頻度を確かめる
        vector<int> id_S(26, 0), id_S_dic(26, 0);
        for (auto c : S.substr(i+1, N-i)) {
            id_S[c - 'a']++;
        }

        // 残っている辞書順の文字列の頻度を確かめる
        for (auto c : S_dic_tmp) {
            id_S_dic[c - 'a']++;
        }

        // 残っている辞書順の各文字について
        for (int k = 0; k < S_dic_tmp.size(); k++) {
            id_S_dic[S_dic_tmp[k] - 'a']--;

            // i+1から末尾まで何文字のコストが発生するか調べる
            min_num = N - i - 1;
            for (int j = 0; j < 26; j++) {                
                min_num -= min(id_S[j], id_S_dic[j]);
            }

            // 見ている文字が元の文字と一緒のとき
            if (S_dic_tmp[k] == S[i]) {
                if (tmp_K >= min_num) {
                    answer += S_dic_tmp[k];
                    S_dic_tmp.erase(S_dic_tmp.begin() + k);
                    break;
                }

            // 見ている文字が元の文字と違うとき、コスト1が発生する
            } else {
                if (tmp_K >= 1 + min_num) {
                    tmp_K -= 1;
                    answer += S_dic_tmp[k];
                    S_dic_tmp.erase(S_dic_tmp.begin() + k);
                    break;
                }
            }

            id_S_dic[S_dic_tmp[k] - 'a']++;
        }
    }
    
    cout << answer << endl;
	return 0;
}
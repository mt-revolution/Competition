#include<bits/stdc++.h>

using namespace std;

// BM法
// BM法のずらし表を返す
vector<int> BM_table(string W) {
    vector<int> table(128, W.size());
    int W_len = W.size();

    for (int i = 0; i < W_len; i++) {
        table[(int)W[i]] = min(table[(int)W[i]], W_len - 1 - i);
    }

    return table;
}


// 文字列Sから文字列Wを検索するBM法
bool BM_search(string S, string W) {
    int W_len = W.size();

    // Sの現在検索中の位置
    int i = W_len-1;
    // Wの現在検索中の位置
    int j = W_len-1;

    vector<int> table = BM_table(W);

    while (i < S.size()) {
        // 文字列が一致する間
        while (W[j] == S[i]) {
            // 全てが一致したとき出力
            if (j == 0) {
                return true;
            } 

            i--, j--;
        }

        // iを次の位置に動かし、jをリセット
        i += max(W_len - j, table[(int)S[i]]);
        j = W_len - 1;
    }  

	return false;
}


int main() {
	long long N;
	cin >> N;
	
	string T;
	cin >> T;

	string S_part = "";
	int len_T = T.size();

	// 適当に200000ぐらいの110の連続した文字列を作る
	for (int i = 0; i < 66700; i++) {
		S_part += "110";
	}

	long long answer;
	long long ALL = 10000000000;

	// BM法で検索して含まれていることが確認できたとき
	if (BM_search(S_part, T) == true) {
		// 文字列の長さが1のとき
		if (T.size() == 1) {
			if (T == "1") {
				answer = 2*ALL;
			} else {
				answer = ALL;
			}
		// 文字列の長さが2のとき
		} else if (T.size() == 2) {
			if (T == "01") {
				answer = ALL - 1;
			} else {
				answer = ALL;
			}
		// 文字列の長さが3以上のとき
		} else {
			if (T.substr(0, 3) == "110") {
				N -= 3;
				
			} else if (T.substr(0, 3) == "101") {
				N -= 2;

			} else if (T.substr(0, 3) == "011") {
				N -= 1;
			}

			if (N % 3 == 0) {
				answer = ALL - (N/3);
			} else {
				answer = ALL - (N/3) - 1;
			}	
		}

		cout << answer << endl;

	// BM法で検索して含まれていなかったとき
	} else {
		cout << 0 << endl;
	}
	
	return 0;
}
#include<bits/stdc++.h>

using namespace std;


int main() {
    int N;
    cin >> N;
    
    string tmp;
    
    // 先頭の桁がi、末尾の桁がjの数の個数
    vector<vector<long long>> num(10, vector<long long>(10, 0));

    int i_tmp, j_tmp, len_tmp;

    // 1<=k<=Nの各kでカウント
    for (int k = 1; k <= N; k++) {
        tmp = to_string(k);
        len_tmp = tmp.size();
        i_tmp = tmp[0] - '0';
        j_tmp = tmp[len_tmp - 1] - '0';
        num[i_tmp][j_tmp]++;
    }

    long long answer = 0;

    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            answer += num[i][j] * num[j][i];
        }
    }

    cout << answer << endl;
	return 0;
}
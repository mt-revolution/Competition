#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    string S;
    cin >> S;

    // 0:A,1:T,2:C,3:G
    vector<vector<int>> count_sum(N+1, vector<int>(4, 0));

    for (int i = 1; i <= N; i++) {
        if (S[i-1] == 'A') {
            count_sum[i][0] = count_sum[i-1][0] + 1;
            count_sum[i][1] = count_sum[i-1][1];
            count_sum[i][2] = count_sum[i-1][2];
            count_sum[i][3] = count_sum[i-1][3];
        } else if (S[i-1] == 'T') {
            count_sum[i][1] = count_sum[i-1][1] + 1;
            count_sum[i][0] = count_sum[i-1][0];
            count_sum[i][2] = count_sum[i-1][2];
            count_sum[i][3] = count_sum[i-1][3];
        } else if (S[i-1] == 'C') {
            count_sum[i][2] = count_sum[i-1][2] + 1;
            count_sum[i][0] = count_sum[i-1][0];
            count_sum[i][1] = count_sum[i-1][1];
            count_sum[i][3] = count_sum[i-1][3];
        } else if (S[i-1] == 'G') {
            count_sum[i][3] = count_sum[i-1][3] + 1;
            count_sum[i][0] = count_sum[i-1][0];
            count_sum[i][1] = count_sum[i-1][1];
            count_sum[i][2] = count_sum[i-1][2];
        }
    }

    int count = 0;

    for (int l = 1; l <= N; l++) {
        for (int w = 1; w <= N-1; w++) {
            int r = l+w;

            if (r > N) {
                break;
            }

            if (count_sum[r][0] - count_sum[l-1][0] == count_sum[r][1] - count_sum[l-1][1] && count_sum[r][2] - count_sum[l-1][2] == count_sum[r][3] - count_sum[l-1][3]) {
                if (count_sum[r][0] - count_sum[l-1][0] > 0 || count_sum[r][1] - count_sum[l-1][1] > 0 || count_sum[r][2] - count_sum[l-1][2] > 0 || count_sum[r][3] - count_sum[l-1][3] > 0) {
                    count++;
                }
            }
        }
    }

    cout << count << endl;
	return 0;
}
#include<bits/stdc++.h>

using namespace std;

const long long INF = 1000000000;

int main() {
    int N;
    cin >> N;

    vector<vector<long long>> A(N, vector<long long>(N));
    vector<vector<long long>> B(N, vector<long long>(N));
    bool flag = true;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> A[i][j];
            B[i][j] = A[i][j];
        }
    }

    for(int k = 0; k < N; k++) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                B[i][j] = min(B[i][j], B[i][k] + B[k][j]);
            }
        }
    }

    long long answer = 0;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            flag = true;
            for(int k = 0; k < N; k++) {
                if(A[i][j] != B[i][j]) {
                    cout << "-1" << endl;
                    return 0;
                }

                if(i == k || j == k) {
                    continue;
                }

                if(A[i][j] == B[i][k] + B[k][j]) {
                    flag = false;
                    break;
                }

            }
            if(flag == true) {
                answer += A[i][j];    
            }
        }
    }

    answer /= 2;

    cout << answer << endl;     
	return 0;
}
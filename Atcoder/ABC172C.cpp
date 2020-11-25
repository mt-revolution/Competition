#include<bits/stdc++.h>
 
using namespace std;
 
int main() {
    int N, M;
    int64_t K;
 
    int64_t time = 0;   
 
    cin >> N >> M >> K;
  
  	int max_ij = 0;
    int max_j = M;
 
    vector<int> A(N, 0);
    vector<int> B(M, 0);
 
    vector<int64_t> A_sum(N+1, 0);
    vector<int64_t> B_sum(M+1, 0);
 
    int i, j;
 
    for(i = 0; i < N; i++) {
        cin >> A.at(i);
    }
 
    for(i = 0; i < M; i++) {
        cin >> B.at(i);
    }
 
    for(i = 0; i <= N; i++) {
        if(i == 0) {
            A_sum[i] = 0;
        } else {
            A_sum[i] += A_sum[i-1] + A.at(i-1);
        }
    }
 
    for(i = 0; i <= M; i++) {
        if(i == 0) {
            B_sum[i] = 0;
        } else {
            B_sum[i] += B_sum[i-1] + B.at(i-1);
        }
    }
 
    
    for(i = 0; i <= N; i++) {
        if(A_sum[i] > K) {
            break;
        }
 
        for(j = max_j; j >= 0; j--) {
            if(B_sum[j] <= K - A_sum[i]) {
                max_j = j;
                break;
            } 
        }
 
        max_ij = max(i + j, max_ij);
    }    
 
    cout << max_ij << endl;
 
	return 0;
}
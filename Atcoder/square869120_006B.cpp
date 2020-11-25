#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;

    cin >> N;
    vector<long long> A(N);
    vector<long long> B(N);
    long long min_sum = 90000000000;
    long long sum = 0;
    long long start, goal;

    for(int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    if(N % 2 == 0) {
        vector<vector<long long>> sg = {{A[N/2], B[N/2]}, {A[N/2-1], B[N/2]}, {A[N/2], B[N/2-1]}, {A[N/2-1], B[N/2-1]}};

        for(int k = 0; k < 4; k++) {
            sum = 0;
            for(int i = 0; i < N; i++) {
                sum += abs(sg[k][0] - A[i]) + abs(A[i] - B[i]) + abs(sg[k][1] - B[i]);
            }
            min_sum = min(min_sum, sum);
        }
    } else {
        start = A[N/2];
        goal = B[N/2];

        for(int i = 0; i < N; i++) {
            sum += abs(start - A[i]) + abs(A[i] - B[i]) + abs(goal - B[i]);
        }
        min_sum = sum;
    }

    cout << min_sum << endl;
	return 0;
}
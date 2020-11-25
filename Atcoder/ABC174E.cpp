#include<bits/stdc++.h>

using namespace std;

int main() {
	long long N, K;
	cin >> N >> K;

	vector<long long> A(N);
    vector<long long> A_(N);
    long long length;
    long long max_length = 0;
	int count = 0;
    int r = 0;

	for(int i = 0; i < N; i++) {
		cin >> A[i];
	}

	sort(A.begin(), A.end());
    reverse(A.begin(), A.end());

    count = K / N;
    r = K % N;

    for(int i = 0; i < N; i++) {
        if(i < r) {
            A_[i] = ceil(A[i] / (count+2));
        } else {
            A_[i] = ceil(A[i] / (count+1));
        }
    }

    for(int i = 0; i < N; i++) {
        if(max_length < A_[i]) {
            max_length = A_[i];
        }
    }

    cout << max_length << endl;
	return 0;
}
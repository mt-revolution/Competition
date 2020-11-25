#include<bits/stdc++.h>

using namespace std;

int main() {
	int N;
    cin >> N;

    vector<int> A(N), B(N), C(N);
    long long count_A = 0, count_C = 0, count = 0;

    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        cin >> B[i];
    }

    for(int i = 0; i < N; i++) {
        cin >> C[i];
    }  

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());

    // Bを固定する
    for(int i = 0; i < N; i++) {
        count_A = 0;
        count_C = 0;

        // AからBより小さい要素の数を数える
        auto iter1 = lower_bound(A.begin(), A.end(), B[i]);
        count_A += iter1 - A.begin();

        // CからBより大きい要素の数を数える
        auto iter2 = upper_bound(C.begin(), C.end(), B[i]);
        count_C += C.end() - iter2;

        // 上の2つをかけてそれぞれのBについて何通り組めるか数える
        count += count_A * count_C;
    }

    cout << count << endl;
	return 0;
}
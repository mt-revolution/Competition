#include<bits/stdc++.h>

using namespace std;

// バブルソート
void bubbleSort(vector<long long> &A, int N) {
    bool flag = true;
    int count = 0;

    while (flag == true) {
        flag = false;
        for (int i = N-1; i > 0; i--) {
            if (A[i] < A[i-1]) {
                swap(A[i], A[i-1]);
                count++;
                flag = true;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        if (i == N-1) {
            cout << A[i];
            continue;
        }
        cout << A[i] << " ";
    }
    cout << endl;

    cout << count << endl;
}

int main() {
    int N;
    cin >> N;
    
    vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    bubbleSort(A, N);
    return 0;
}
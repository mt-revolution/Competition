#include<bits/stdc++.h>

using namespace std;

int n;

void CountingSort(vector<int> &A, vector<int> &B, int k) {
    vector<int> C(k+1, 0);

    for (int j = 1; j <= n; j++) {
        C[A[j]]++;
    }

    for (int i = 1; i <= k; i++) {
        C[i] += C[i-1];
    }

    for (int j = n; j >= 1; j--) {
        B[C[A[j]]] = A[j];
        C[A[j]]--;
    }
}


int main() {
    cin >> n;
    
    vector<int> A(n+1), B(n+1);
    int A_max = 0;

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        A_max = max(A_max, A[i]);
    }

    CountingSort(A, B, A_max);

    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            cout << B[i];
            continue;
        }
        cout << " " << B[i];
    }

    cout << endl;
    return 0;
}
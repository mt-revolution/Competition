#include<bits/stdc++.h>

using namespace std;

int value(string S) {
    return S[1] - '0';
}

// バブルソート
void bubbleSort(vector<string> &C, int N) {
    bool flag = true;

    while (flag == true) {
        flag = false;
        for (int i = N-1; i > 0; i--) {
            if (value(C[i]) < value(C[i-1])) {
                swap(C[i], C[i-1]);
                flag = true;
            }
        }
    }
}

// 選択ソート
void selectionSort(vector<string> &C, int N) {
    int min_j;

    for (int i = 0; i < N; i++) {
        min_j = i;
        for (int j = i; j < N; j++) {
            if (value(C[j]) < value(C[min_j])) {
                min_j = j;
            }
        }

        swap(C[i], C[min_j]);
    }
}

int main() {
    int N;
    cin >> N;
    
    vector<string> C(N);
    for (int i = 0; i < N; i++) {
        cin >> C[i];
    }

    vector<string> C_bubble = C, C_selection = C;

    bubbleSort(C_bubble, N);
    selectionSort(C_selection, N);

    for (int i = 0; i < N; i++) {
        if (i == N-1) {
            cout << C_bubble[i];
            continue;
        }
        cout << C_bubble[i] << " ";
    }
    cout << endl;
    cout << "Stable" << endl;

    bool flag = true;

    for (int i = 0; i < N; i++) {
        if (C_selection[i] != C_bubble[i]) {
            flag = false;
        }

        if (i == N-1) {
            cout << C_selection[i];
            continue;
        }
        cout << C_selection[i] << " ";
    }
    cout << endl;

    if (flag == true) {
        cout << "Stable" << endl;     
    } else {
        cout << "Not stable" << endl;
    }

    return 0;
}
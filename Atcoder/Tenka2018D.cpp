#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> candidate;
    bool flag = false;

    for (int k = 0; k*(k-1)/2 <= 100000; k++) {
        candidate.push_back(k*(k-1)/2);
    }

    for (int k = 2; k < candidate.size(); k++) {
        if (N == candidate[k]) {
            flag = true;

            vector<vector<int>> S(k, vector<int>{});
            int num = 1;

            for (int i = 0; i < k-1; i++) {
                for (int j = i+1; j < k; j++) {
                    S[i].push_back(num);
                    S[j].push_back(num);
                    num++;
                }
            }

            cout << "Yes" << endl;
            cout << k << endl;
            for (int i = 0; i < k; i++) {
                cout << S[i].size();

                for (auto j : S[i]) {
                    cout << " " << j;
                }
                cout << endl;
            }
        }
    }

    if (flag == false) {
        cout << "No" << endl;
    }
    return 0;
}
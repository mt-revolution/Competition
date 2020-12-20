#include<bits/stdc++.h>

using namespace std;


int main() {
    int n,k;
    cin >> n >> k;

    vector<string> A(n);
    
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    // 順列用
    vector<int> perm;

    for (int i = 0; i < n; i++) {
        perm.push_back(i);
    }

    // 出来た整数のマップ
    map<string, int> count;
    string tmp;
    int answer = 0;

    // 順列全探索
    do {
        tmp = "";
        for (int i = 0; i < k; i++) {
            tmp += A[perm[i]];
        }

        count[tmp]++;

    } while(next_permutation(perm.begin(), perm.end()));

    for (auto i : count) {
        answer++;
    }

    cout << answer << endl;
	return 0;
}
#include<bits/stdc++.h>

using namespace std;


int main() {
    int n,k;
    cin >> n >> k;

    vector<int> A(n);
    
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    // 順列用
    vector<int> perm;

    for (int i = 0; i < n; i++) {
        perm.push_back(i);
    }

    // 出来た整数の集合
    set<int> num;
    string tmp;
    int tmp_num;
    int answer = 0;

    // 順列全探索
    do {
        tmp = "";
        for (int i = 0; i < k; i++) {
            tmp += to_string(A[perm[i]]);
        }

        tmp_num = stoi(tmp);
        num.insert(tmp_num);

    } while(next_permutation(perm.begin(), perm.end()));

    answer = num.size();

    cout << answer << endl;
	return 0;
}
#include<bits/stdc++.h>

using namespace std;

// vectorから要素を検索
bool vector_finder(vector<int> vec, int number) {
    auto itr = find(vec.begin(), vec.end(), number);
    size_t index = distance( vec.begin(), itr );
    if (index != vec.size()) { // 発見できたとき
        return true;
    }
    else { // 発見できなかったとき
        return false;
    }
}

int main() {
    int n,q;
    cin >> n;

    vector<int> A(n);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    cin >> q;
    vector<int> m(q);

    for (int i = 0; i < q; i++) {
        cin >> m[i];
    }

    int count = 0;
    vector<int> sum;

    for (int biti = 0; biti < (1<<n); biti++) {
        count = 0;

        for (int i = 0; i < n; i++) {
            if (biti & (1<<i)) {
                count += A[i];
            }
        }

        sum.push_back(count);
    }

    for (int k = 0; k < q; k++) {
        if (vector_finder(sum, m[k]) == true) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }    

	return 0;
}
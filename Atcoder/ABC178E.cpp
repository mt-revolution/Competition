#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1000000007;


int main() {
    int N;
    cin >> N;

    long long x,y;
    vector<long long> x_(N), y_(N);

    // 45度回転座標系に変換する
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        x_[i] = x - y;
        y_[i] = x + y;
    }

    // 昇順ソートして一番小さい値と一番大きい値の差を取る
    sort(x_.begin(), x_.end());
    sort(y_.begin(), y_.end());

    long long answer = max(abs(x_.front() - x_.back()), abs(y_.front() - y_.back()));

    cout << answer << endl;
    return 0;
}
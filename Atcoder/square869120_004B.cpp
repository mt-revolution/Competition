#include<bits/stdc++.h>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<long long> a(N);
    vector<long long> tmp_a(N);
    long long money = 0;
    long long min_money = 15000000000;
    vector<int> digit;
    long long current_max_height;
    int count = 0;

    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }

    // どのビルを高くしてどのビルをそのままにするか全探索
    for(int biti = 0; biti < (1<<(N-1)); biti++) {
        tmp_a = a;
        money = 0;
        digit = {};

        // 高くするビルを格納
        for(int i = 0; i < N-1; i++) {
            if(biti & (1<<i)) {
                digit.push_back(i);
            }
        }

        // 選んだビルを高くして金額を計算
        for(int i : digit) {
            current_max_height = *max_element(tmp_a.begin(), tmp_a.begin() + (i+1));
            if(tmp_a[i+1] <= current_max_height) {
                money += current_max_height - tmp_a[i+1] + 1;
                tmp_a[i+1] = current_max_height + 1;
            }
        }

        // 左から見えるビルの数を数える
        count = 1;
        for(int i = 1; i < N; i++) {
            current_max_height = *max_element(tmp_a.begin(), tmp_a.begin() + i);
            if(tmp_a[i] > current_max_height) {
                count++;
            }
        }

        // 左から見えるビルがK個なら金額の結果を最小値の候補にする
        if(count == K) {
            min_money = min(min_money, money);
        }
    }

    cout << min_money << endl;
	return 0;
}
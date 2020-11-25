#include<bits/stdc++.h>

using namespace std;

int main() {
    int d, n, m;
    cin >> d;
    cin >> n;
    cin >> m;

    vector<int> shop(n+1);
    vector<int> destination(m);
    int sum = 0;

    shop[0] = 0;
    shop[1] = d;

    for(int i = 2; i < n+1; i++) {
        cin >> shop[i];
    }

    for(int i = 0; i < m; i++) {
        cin >> destination[i];
    }

    sort(shop.begin(), shop.end());

    // 店舗の座標から目的地の座標を二分探索
    for(int i = 0; i < m; i++) {
        auto iter1 = lower_bound(shop.begin(), shop.end(), destination[i]);
        if(iter1 - 1 >= shop.begin()) {
            auto iter2 = iter1 - 1;
            sum += min(abs(*iter1 - destination[i]), abs(*iter2 - destination[i]));
        } else {
            sum += abs(*iter1 - destination[i]);
        }
    }

    cout << sum << endl;    
    return 0;
}
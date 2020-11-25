#include<bits/stdc++.h>

using namespace std;


int main() {
    vector<int> number;
    int input;

    while(1) {
        cin >> input;
        if(input == 0) {
            break;
        }

        number.push_back(input);
    }

    
    // 正四面体数
    vector<int> tetra;
    tetra.push_back(0);
    int k = 0;


    while(1) {
        k++;
        tetra.push_back(k*(k+1)*(k+2)/6);

        if(k*(k+1)*(k+2)/6 > 1000000) {
            break;
        }
    }


    // iを正四面体数の和として表したときの正四面体の個数の最小値dp1[i]
    vector<int> dp1(1000000, 1000000);
    // iを奇数の正四面体数の和として表したときの正四面体の個数の最小値dp2[i]
    vector<int> dp2(1000000, 1000000);

    // 初期条件
    dp1[0] = 0, dp2[0] = 0, dp1[1] = 1, dp2[1] = 1;

    // dp開始
    for(int i = 2; i < 1000000; i++) {
        for(int j = 1; tetra[j] <= i; j++) {
            dp1[i] = min(dp1[i], dp1[i-tetra[j]] + 1);

            if(tetra[j] % 2 == 1) {
                dp2[i] = min(dp2[i], dp2[i-tetra[j]] + 1);
            }
        }
    }

    for(int num : number) {
        cout << dp1[num] << " " << dp2[num] << endl;
    }
    
    return 0;
}
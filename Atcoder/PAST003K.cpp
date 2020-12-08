#include<bits/stdc++.h>

using namespace std;


int main() {
	int N,Q;
    cin >> N >> Q;
    
    int f,t,x;

    // 各机の頂上のコンテナ
    vector<int> top(N);

    for (int i = 0; i < N; i++) {
        top[i] = i;
    }

    // 各コンテナの1つ下のコンテナ
    vector<int> lower_container(N, -1);
    int tmp;

    for (int i = 0; i < Q; i++) {
        cin >> f >> t >> x;
        f--, t--, x--;
        
        // 移動元の頂上を今のコンテナxの下のコンテナに、コンテナxの下のコンテナを移動先の頂上に、移動先の頂上を移動元の頂上に
        tmp = top[f];
        top[f] = lower_container[x];
        lower_container[x] = top[t];
        top[t] = tmp;        
    }

    // 各コンテナがどの机にあるのか
    vector<int> where(N);

    // 各机の頂上からコンテナがなくなるまで探索
    for (int i = 0; i < N; i++) {
        tmp = top[i];

        while (tmp != -1) {
            where[tmp] = i;
            tmp = lower_container[tmp];
        }
    }

    for (int i = 0; i < N; i++) {
        cout << where[i]+1 << endl;
    }
	return 0;
}
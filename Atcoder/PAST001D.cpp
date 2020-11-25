#include<bits/stdc++.h>

using namespace std;

int main() {
	int N;
    cin >> N;
    
    vector<int> id(N+1, 0);
    int A;
    for (int i = 0; i < N; i++) {
        cin >> A;
        id[A] += 1;
    }

    int x,y;
    bool flag = false;

    for (int i = 1; i <= N; i++) {
        if (id[i] == 2) {
            flag = true;
            y = i;
        } else if (id[i] == 0) {
            flag = true;
            x = i;
        }
    }

    if (flag == true) {
        cout << y << " " << x << endl;
    } else {
        cout << "Correct" << endl;
    }
	return 0;
}
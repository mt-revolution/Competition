#include<bits/stdc++.h>

using namespace std;

int main() {
	int n;
    cin >> n;

    vector<pair<int, int>> c;
    int tmp = 0, a;

    cin >> a;
    c.push_back(make_pair(a, 1));

    for (int i = 1; i <= n-1; i++) {
        cin >> a;

        if (i % 2 == 0) {
            if (c[tmp].first == a) {
                c[tmp].second++;
            } else {
                c.push_back(make_pair(a, 1));
                tmp++;
            }
        } else {
            if (c[tmp].first == a) {
                c[tmp].second++;
            } else {
                if (tmp > 0) {
                    c[tmp-1].second += c[tmp].second + 1;
                    c.pop_back();
                    tmp--;
                } else {
                    c[0].first = 1 - c[0].first;
                    c[0].second++;
                }
            }
        }
    }

    int answer = 0;

    for (auto i : c) {
        if (i.first == 0) {
            answer += i.second;  
        }
    }

    cout << answer << endl;  
	return 0;
}
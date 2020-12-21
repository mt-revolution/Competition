#include<bits/stdc++.h>

using namespace std;

// pairの2番目の値で昇順ソート
bool comp(pair<int, int> a, pair<int, int> b) {
    if(a.second != b.second){
        return a.second < b.second;
    }else{
        return a.first < b.first;
    }
}

int main() {
	int N;
	cin >> N;

	vector<pair<int, int>> red(N), blue(N);
	int a,b,c,d;
	
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		red[i] = make_pair(a, b);
	}

	for (int i = 0; i < N; i++) {
		cin >> c >> d;
		blue[i] = make_pair(c, d);
	}

	// 赤のx座標で降順ソート、青のy座標で昇順ソート
	sort(red.rbegin(), red.rend());
	sort(blue.begin(), blue.end(), comp);

	int answer = 0;
	vector<int> blue_id(N, 0);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (red[i].first < blue[j].first && red[i].second < blue[j].second) {
				if (blue_id[j] == 0) {
					answer++;
					blue_id[j] = 1;
					break;
				}
			}
		}
	}

	cout << answer << endl;
	return 0;
}
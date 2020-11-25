#include<bits/stdc++.h>

using namespace std;

int main() {
	int X,Y,A,B,C;
	cin >> X >> Y >> A >> B >> C;
	
	vector<long long> p(A), q(B), r(C);

	// 候補のりんご
	vector<long long> apple;

	for (int i = 0; i < A; i++) {
		cin >> p[i];
	}

	for (int i = 0; i < B; i++) {
		cin >> q[i];
	}

	for (int i = 0; i < C; i++) {
		cin >> r[i];
		apple.push_back(r[i]);
	}

	// 各りんごを美味しさの大きい順に並べる
	sort(p.begin(), p.end());
	reverse(p.begin(), p.end());
	sort(q.begin(), q.end());
	reverse(q.begin(), q.end());
	sort(r.begin(), r.end());
	reverse(r.begin(), r.end());

	// pから上位X個をとる
	for (int i = 0; i < X; i++) {
		apple.push_back(p[i]);
	}

	// qから上位Y個をとる
	for (int i = 0; i < Y; i++) {
		apple.push_back(q[i]);
	}

	// 候補のりんごを美味しさの大きい順に並べる
	sort(apple.begin(), apple.end());
	reverse(apple.begin(), apple.end());

	long long answer = 0;

	// 候補のりんごから上位X+Y個を選ぶ
	for (int i = 0; i < X+Y; i++) {
		answer += apple[i];
	}

	cout << answer << endl;
	return 0;
}
#include<bits/stdc++.h>

using namespace std;



int main() {
	int N;
	int delta_t, delta_x, delta_y;
	string result = "Yes";
	
	cin >> N;

	vector<int> t(N+1);
	vector<int> x(N+1);
	vector<int> y(N+1);

	t.at(0) = 0;
	x.at(0) = 0;
	y.at(0) = 0;

	for (int i = 1; i <= N; i++) {
		cin >> t.at(i) >> x.at(i) >> y.at(i);
	}

	for (int i = 1; i <= N; i++) {
		delta_t = t.at(i) - t.at(i - 1);
		delta_x = x.at(i) - x.at(i - 1);
		delta_y = y.at(i) - y.at(i - 1);

		while (delta_t > 0) {
			if (delta_x > 0) {
				delta_x -= 1;
			}
			else if (delta_x < 0) {
				delta_x += 1;
			}
			else if (delta_y > 0) {
				delta_y -= 1;
			}
			else if (delta_y < 0) {
				delta_y += 1;
			}
			else if (delta_x == 0) {
				delta_x += 1;
			}
			else if (delta_y == 0) {
				delta_y += 1;
			}

			delta_t -= 1;
		}

		if (delta_x != 0 || delta_y != 0) {
			result = "No";
			break;
		}

	}

	cout << result << endl;
	return 0;
}
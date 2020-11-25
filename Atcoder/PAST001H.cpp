#include<bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin >> N;
	
	vector<long long> c(N);
	long long min_set = 10000000000000000, min_all = 10000000000000000;
	long long answer = 0;

	for (int i = 0; i < N; i++) {
		cin >> c[i];
		
		if (i % 2 == 0) {
			min_set = min(min_set, c[i]);
		}

		min_all = min(min_all, c[i]);
	}

	int Q;
	cin >> Q;
	int num,a,b;
	vector<long long> count(N, 0);
	long long count_2 = 0, count_3 = 0;
	
	for (int i = 0; i < Q; i++) {
		cin >> num;

		if (num == 1) {
			cin >> a >> b;
			a--;

			if (a % 2 == 0) {
				if (b <= c[a] - count[a] - count_2 - count_3) {
					min_set = min(min_set, c[a] - count[a] - count_2 - count_3 - b);
					min_all = min(min_all, c[a] - count[a] - count_2 - count_3 - b);

					count[a] += b;
					answer += b;
				}
			} else {
				if (b <= c[a] - count[a] - count_3) {
					min_all = min(min_all, c[a] - count[a] - count_3 - b);
					
					count[a] += b;
					answer += b;
				}
			}
			
		} else if (num == 2) {
			cin >> b;

			if (b <= min_set) {
				min_set -= b;
				min_all = min(min_all, min_set);
				count_2 += b;

				if (N % 2 == 0) {
					answer += b * (N/2);	
				} else {
					answer += b * ((N+1)/2);
				}
			}

			
		} else if (num == 3) {
			cin >> b;

			if (b <= min_all) {
				min_set -= b;
				min_all -= b;
				count_3 += b;
				answer += b * N;
			}		
		}
	}

	cout << answer << endl;
	return 0;
}
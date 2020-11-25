#include<bits/stdc++.h>

using namespace std;

int main() {
	int N,M;
    cin >> N >> M;
    
    vector<double> x(N+M), y(N+M), r(N);
    double distance;
    double answer = 1000000000;
    
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i] >> r[i];
    }

    for (int i = N; i < N+M; i++) {
        cin >> x[i] >> y[i];
    }

    if (M == 0) {
        for (int i = 0; i < N; i++) {
            answer = min(answer, r[i]);
        }
    }

    for (int i = N; i < N+M; i++) {
        for (int j = 0; j < N+M; j++) {
            if (j == i) {
                continue;
            }

            distance = sqrt(pow(x[i] - x[j], 2.0) + pow(y[i] - y[j], 2.0));

            if (j < N) {
                answer = min(answer, distance - r[j]);
            } else {
                answer = min(answer, distance / 2.0);
            }

            
        }
    }

    cout << fixed << setprecision(15) << answer << endl;
	return 0;
}
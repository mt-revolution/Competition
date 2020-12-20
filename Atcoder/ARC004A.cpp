#include<bits/stdc++.h>

using namespace std;

int main() {
	int N;
    cin >> N;
    
    double answer = 0;
    vector<double> x(N), y(N);

    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }

    for (int i = 0; i < N-1; i++) {
        for (int j = i+1; j < N; j++) {
            answer = max(answer, sqrt(pow(x[i] - x[j], 2.0) + pow(y[i] - y[j], 2.0)));
        }
    }

    cout << fixed << setprecision(10) << answer << endl;
	return 0;
}
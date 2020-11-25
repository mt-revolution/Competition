#include<bits/stdc++.h>

using namespace std;


int main() {
    int N;
    cin >> N;

    long long x;
    long long man = 0, chebi = 0;
    long long euq_sum = 0;
    double euq;
    for (int i = 0; i < N; i++) {
        cin >> x;
        man += abs(x);
        euq_sum += x*x;
        chebi = max(chebi, abs(x));
    }

    euq = sqrt((double)euq_sum);

    cout << man << endl;
    cout << fixed << setprecision(15) << euq << endl;
    cout << chebi << endl;
    return 0;
}
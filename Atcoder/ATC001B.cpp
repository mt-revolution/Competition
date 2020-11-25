#include<bits/stdc++.h>

using namespace std;

int root(vector<int> &parent, int x) {
    if(parent.at(x) == x) {
        return x;
    } else {
        return parent.at(x) = root(parent, parent.at(x));
    }
}

void connect(vector<int> &parent, int n1, int n2) {
    n1 = root(parent, n1);
    n2 = root(parent, n2);

    if(n1 == n2) {
        return;
    }

    parent.at(n1) = n2;
}

bool connected(vector<int> &parent, int n1, int n2) {
    if(root(parent, n1) == root(parent, n2)) {
        return true;
    } else {
        return false;
    }
} 

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> P(Q);
    vector<int> A(Q);
    vector<int> B(Q);
    vector<int> parent(N);

    for(int i = 0; i < Q; i++) {
        cin >> P.at(i) >> A.at(i) >> B.at(i);
    }

    for(int i = 0; i < N; i++) {
        parent.at(i) = i;
    }


    for(int i = 0; i < Q; i++) {
        if(P.at(i) == 0) {
            connect(parent, A.at(i), B.at(i));
        } else {
            if(connected(parent, A.at(i), B.at(i)) == true) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }

	return 0;
}
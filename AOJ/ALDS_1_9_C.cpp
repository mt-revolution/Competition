#include<bits/stdc++.h>

using namespace std;

void insert(priority_queue<int> &S, int k) {
    S.push(k);
}

int extractMax(priority_queue<int> &S) {
    int a = S.top();
    S.pop();
    return a;
}

int main() {
    priority_queue<int> queue;
    
    string s;
    int v;

    while (1) {
        cin >> s;
        
        if (s == "insert") {
            cin >> v;
            insert(queue, v);
        } else if (s == "extract") {
            cout << extractMax(queue) << endl;
        } else if (s == "end") {
            break;
        }
    }
    return 0;
}
#include<bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;
    
    list<int> num;
    string s;
    int key;

    for (int i = 0; i < n; i++) {
        cin >> s;
        
        if (s == "insert") {
            cin >> key;
            num.push_front(key);
        } else if (s == "delete") {
            cin >> key;
            
            for (auto iter = num.begin(); iter != num.end(); iter++) {
                if (*iter == key) {
                    num.erase(iter);
                    break;
                }
            }
        } else if (s == "deleteFirst") {
            num.pop_front();
        } else if (s == "deleteLast") {
            num.pop_back();
        }
    }

    for (auto iter = num.begin(); iter != num.end(); iter++) {
        if (iter == num.begin()) {
            cout << *iter;
            continue;
        }
        cout << " " << *iter;
    }
    cout << endl;
    return 0;
}
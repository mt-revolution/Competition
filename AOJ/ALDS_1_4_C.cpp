#include<bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;
    string operation, str;
    set<string> dictionary;
    
    for (int i = 0; i < n; i++) {
        cin >> operation >> str;
        if (operation == "insert") {
            dictionary.insert(str);
        } else if (operation == "find") {
            if (dictionary.find(str) == dictionary.end()) {
                cout << "no" << endl;
            } else {
                cout << "yes" << endl;
            }
        }
    }
    return 0;
}
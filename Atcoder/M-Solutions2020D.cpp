#include<bits/stdc++.h>
 
using namespace std;
 
int main() {
    int N;
    cin >> N;
 
    long long money = 1000;
    long long stock = 0;
 
    vector<int> A(N);
 
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
 
    for(int i = 0; i < N-1; i++) {
        // 株価が上がるときは金をつぎ込んで変えるだけ買う
        if(A[i] < A[i+1]) {
            stock += money / A[i];
          	money -= (money / A[i]) * A[i];
                
        // 株価が下がるときは持ってる分を全て売る
        } else if(A[i] > A[i+1]) {
      		money += stock * A[i];
      		stock = 0;           
        }
    }
 
    // 最後に残ってる株を全て売る
    money += stock * A[N-1];
    stock = 0;
 
    cout << money << endl;    
	return 0;
}
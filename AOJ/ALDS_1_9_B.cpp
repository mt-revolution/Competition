#include<bits/stdc++.h>

using namespace std;

int H;

void maxHeapify(vector<int> &A, int i) {
    int l = 2*i;
    
    int r = 2*i+1;
    int largest;

    if (l <= H && A[l] > A[i]) {
        largest = l;
    } else {
        largest = i;
    }
    if (r <= H && A[r] > A[largest]) {
        largest = r;
    }

    if (largest != i) {
        swap(A[i], A[largest]);
        maxHeapify(A, largest);
    }  
}

void buildMaxHeap(vector<int> &A) {
    for (int i = H/2; i >= 1; i--) {
        maxHeapify(A, i);
    }
}



int main() {
    cin >> H;

    int v;
    vector<int> Heap(H+1);

    for (int i = 1; i <= H; i++) {
        cin >> Heap[i];
    }

    buildMaxHeap(Heap);

    for (int i = 1; i <= H; i++) {
        cout << " " << Heap[i];
    }
    cout << endl;
    return 0;
}
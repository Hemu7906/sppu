#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& v, int l, int h) {
    int pivot = v[l];
    int i = l - 1, j = h + 1;

    while (true) {
        do {
            i++;
        } while (v[i] < pivot);
        do {
            j--;
        } while (v[j] > pivot);
        if (i >= j) 
            return j;
        
        swap(v[i], v[j]);
    }
}

void qsort(vector<int>& v, int l, int h) {
    if (l < h) {
        int p = partition(v, l, h);
        qsort(v, l, p);
        qsort(v, p + 1, h);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    qsort(v, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}

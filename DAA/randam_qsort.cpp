#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr, int low, int high) {

    srand(time (NULL));
    int random = low + (rand() % (high - low));

    swap(arr[random], arr[low]);

    int pivot = low;
    int i = low + 1, j = high;

    while (i <= j) {
        while (i <= high && arr[i] <= arr[pivot]) {
            i++;
        }
        while (j >= low + 1 && arr[j] >= arr[pivot]) {
            j--;
        }
        if (j < i)break;
        swap(arr[i], arr[j]);
    }

    swap(arr[pivot], arr[j]);
    return j;
}

void quickSort(vector<int>& arr, int low, int high) {

    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5, 64, 4, 43, 524, 556, 3, 45, 7, 344, 37, 45, 5, 356, 56, 356, 45, 356, 236, 6, 36, 35, 63, 635, 63, 63, 43};
    int n = arr.size();
    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
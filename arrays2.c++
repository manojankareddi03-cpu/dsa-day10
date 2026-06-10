#include <iostream>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low;

    for(int j = low; j < high; j++) {
        if(arr[j] <= pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }

    swap(arr[i], arr[high]);
    return i;
}

int quickSelect(int arr[], int low, int high, int k) {

    if(low <= high) {

        int p = partition(arr, low, high);

        if(p == k - 1)
            return arr[p];

        else if(p > k - 1)
            return quickSelect(arr, low, p - 1, k);

        else
            return quickSelect(arr, p + 1, high, k);
    }

    return -1;
}

int main() {

    int arr[] = {7,10,4,3,20,15};
    int n = 6;
    int k = 3;

    cout << quickSelect(arr, 0, n - 1, k);

    return 0;
}

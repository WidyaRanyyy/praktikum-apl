#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int interpolationSearch(int arr[], int lo, int hi, int x) {
    int pos;
    if (lo <= hi && x >= arr[lo] && x <= arr[hi]) {
        pos = lo + (((int)(hi - lo) / (arr[hi] - arr[lo])) * (x - arr[lo]));
        cout << "pos: " << pos << endl;
        if (arr[pos] == x)
        return pos;
        if (arr[pos] < x)
        return interpolationSearch(arr, pos + 1, hi, x);
        if (arr[pos] > x)
        return interpolationSearch(arr, lo, pos - 1, x);
    }
    return -1;
}
int main() {
    int arr[] = {0, 1, 2, 5, 8, 21, 72, 89, 99};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 72;
    int index = interpolationSearch(arr, 0, n - 1, x);
    if (index != -1)
        cout << "Element found at index " << index << endl;
    else
        cout << "Element not found." << endl;
    return 0;
}
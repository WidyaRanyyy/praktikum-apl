#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int jumpSearch(int arr[], int x, int n) {
    int step = sqrt(n);
    int prev = 0;
    while (arr[min(step, n) - 1] < x) {
        prev = step;
        step += sqrt(n);
        if (prev >= n)
        return -1;
    }
    while (arr[prev] < x) {
        prev++;
        if (prev == min(step, n))
        return -1;
    }
    if (arr[prev] == x)
    return prev;
    return -1;
}
int main() {
    int arr[] = {0, 1, 2, 5, 8, 21, 89, 99};
    int x = 21;
    int n = sizeof(arr) / sizeof(arr[0]);
    int index = jumpSearch(arr, x, n);
    if (index == -1) {
        cout << "\nAngka " << x << " tidak ada di dalam array" << endl;
    } else {
        cout << "\nAngka" << x << " berada pada index " << index << endl;
    }
    return 0;
}
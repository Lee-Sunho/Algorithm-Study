#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        cout << mid << '\n';
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    vector<int> arr = {1, 6, 3, 10, 9, 30, 22, 21};
    sort(arr.begin(), arr.end());

    int target;
    cin >> target;
    int result = binarySearch(arr, target);

    if (result != -1) {
        cout << "Target found at index: " << result << "\n";
    } else {
        cout << "Target not found int the array\n";
    }

    return 0;
}
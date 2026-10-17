#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int t, n, m;

string binarySearch(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == target)
            return "큰돌이는 기억해!";
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return "큰돌이는 까먹었어!";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> v1, v2;

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            v1.push_back(x);
        }

        cin >> m;
        for (int i = 0; i < m; i++) {
            int x;
            cin >> x;
            v2.push_back(x);
        }

        sort(v1.begin(), v1.end());

        for (int target : v2) {
            cout << binarySearch(v1, target) << '\n';
        }
    }

    return 0;
}
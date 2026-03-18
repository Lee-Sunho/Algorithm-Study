#include <bits/stdc++.h>
using namespace std;

int n, x;
vector<int> v, temp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        v.push_back(x);
        temp.push_back(x);
    }

    sort(temp.begin(), temp.end());
    temp.erase(unique(temp.begin(), temp.end()), temp.end());

    for (int i = 0; i < v.size(); i++) {
        auto itr = lower_bound(temp.begin(), temp.end(), v[i]);
        cout << itr - temp.begin() << ' ';
    }

    return 0;
}
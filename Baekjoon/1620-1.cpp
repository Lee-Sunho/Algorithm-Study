#include <bits/stdc++.h>
using namespace std;

int n, m;
string arr[100004];
unordered_map<string, int> umap;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        umap[arr[i]] = i;
    }

    for (int i = 0; i < m; i++) {
        string question;
        cin >> question;

        if (isdigit(question[0])) {
            cout << arr[stoi(question)] << '\n';
        } else {
            cout << umap[question] << '\n';
        }
    }
}
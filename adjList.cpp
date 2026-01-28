#include <bits/stdc++.h>
using namespace std;

const int N = 4;
bool visited[N];
vector<int> adj[N];

void go(int from) {
    cout << from << '\n';
    visited[from] = 1;

    for (int x : adj[from]) {
        if (visited[x] == 0) {
            go(x);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[0].push_back(3);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[2].push_back(1);
    adj[3].push_back(0);

    for (int i = 0; i < N; i++) {
        if (adj[i].size() && visited[i] == 0) {
            go(i);
        }
    }

    return 0;
}
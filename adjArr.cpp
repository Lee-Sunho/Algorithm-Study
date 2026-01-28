#include <bits/stdc++.h>
using namespace std;

bool adj[10][10], visited[10];

void go(int from) {
    cout << from << '\n';
    visited[from] = 1;

    for (int i = 0; i < 10; i++) {
        if (adj[from][i] && visited[i] == 0) {
            go(i);
        }
    }
}

int main() {
    adj[1][2] = 1;
    adj[2][1] = 1;
    adj[1][3] = 1;
    adj[3][1] = 1;
    adj[3][4] = 1;
    adj[4][3] = 1;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (adj[i][j] && visited[i] == 0) {
                go(i);
            }
        }
    }

    return 0;
}
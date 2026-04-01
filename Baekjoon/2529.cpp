#include <bits/stdc++.h>
using namespace std;

int k, visited[10];
char op[10];

string ret;
vector<string> results;

void func(int depth) {
    if (depth == k) {
        results.push_back(ret);
        return;
    }

    for (int i = 0; i < 10; i++) {
        if (op[depth] == '<') {
            if (visited[i] == 0 && ret[depth] - '0' < i) {
                visited[i] = 1;
                ret += to_string(i);
                func(depth + 1);
                ret.pop_back();
                visited[i] = 0;
            }
        } else if (op[depth] == '>') {
            if (visited[i] == 0 && ret[depth] - '0' > i) {
                visited[i] = 1;
                ret += to_string(i);
                func(depth + 1);
                ret.pop_back();
                visited[i] = 0;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> op[i];
    }

    for (int i = 0; i < 10; i++) {
        visited[i] = 1;
        ret += to_string(i);
        func(0);
        ret.pop_back();
        visited[i] = 0;
    }

    sort(results.begin(), results.end());
    cout << results.back() << '\n';
    cout << results.front() << '\n';

    return 0;
}
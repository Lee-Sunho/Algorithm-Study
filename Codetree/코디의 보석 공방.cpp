#include <math.h>

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int q;
vector<pair<int, int>> jewel;
bool isSell[1204];

bool cmp(pair<int, int> p1, pair<int, int> p2) {
    return p1.second > p2.second;
}

void init() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int w, v;
        cin >> w >> v;
        jewel.push_back({w, v});
    }
}

void input() {
    int w, v;
    cin >> w >> v;
    jewel.push_back({w, v});
}

void sell() {
    int num;
    cin >> num;
    int idx = num - 1;

    if (idx < 0 || idx >= jewel.size() || isSell[idx])
        cout << -1 << '\n';
    else {
        isSell[idx] = true;
        cout << jewel[idx].second << '\n';
    }
}

void display() {
    int max_w;
    cin >> max_w;

    vector<int> dp(max_w + 1, 0);

    for (int i = 0; i < jewel.size(); i++) {
        if (isSell[i]) continue;
        for (int w = max_w; w >= jewel[i].first; w--) {
            dp[w] = max(dp[w], dp[w - jewel[i].first] + jewel[i].second);
        }
    }

    cout << dp[max_w] << '\n';
}

int combi(int start, vector<int>& temp, int diff) {
    int ret = 0;
    if (temp.size() == 2) {
        int w1 = jewel[temp[0]].first;
        int w2 = jewel[temp[1]].first;
        if (abs(w1 - w2) <= diff)
            return 1;
        else
            return 0;
    }

    for (int i = start + 1; i < jewel.size(); i++) {
        if (!isSell[i]) {
            temp.push_back(i);
            ret += combi(i, temp, diff);
            temp.pop_back();
        }
    }
    return ret;
}

void bundle() {
    int diff;
    cin >> diff;

    vector<int> weights;
    for (int i = 0; i < jewel.size(); i++) {
        if (!isSell[i]) weights.push_back(jewel[i].first);
    }

    if (weights.size() < 2) {
        cout << 0 << '\n';
        return;
    }

    sort(weights.begin(), weights.end());

    long long cnt = 0;
    int right = 0;
    for (int left = 0; left < weights.size(); left++) {
        while (right < weights.size() && weights[right] - weights[left] <= diff) {
            right++;
        }
        cnt += right - left - 1;
    }
    cout << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> q;
    for (int i = 0; i < q; i++) {
        int work_num;
        cin >> work_num;

        switch (work_num) {
            case 1:
                init();
                break;
            case 2:
                input();
                break;
            case 3:
                sell();
                break;
            case 4:
                display();
                break;
            case 5:
                bundle();
                break;
        }
    }

    return 0;
}
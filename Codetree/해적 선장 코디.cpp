#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

struct Ship {
    int id;
    int p;  // 공격력
    int r;  // 재장전 시간
    int last_attack = -1;
};

int T, cur_t;
unordered_map<int, Ship> m_ship;
priority_queue<pair<int, int>> pq;  // [공격력, -id]

void init() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int id, p, r;
        cin >> id >> p >> r;
        m_ship[id] = {id, p, r};
        pq.push({p, -id});
    }
}

void add() {
    int id, p, r;
    cin >> id >> p >> r;
    m_ship[id] = {id, p, r};
    pq.push({p, -id});
}

void change() {
    int id, p;
    cin >> id >> p;

    m_ship[id].p = p;
    pq.push({p, -id});
}

void attack() {
    int cnt = 0, psum = 0;
    vector<pair<int, int>> v_num;
    vector<pair<int, int>> v_wait;

    while (!pq.empty() && v_num.size() < 5) {
        auto target = pq.top();
        int p = target.first;
        int id = target.second * -1;
        pq.pop();

        if (p != m_ship[id].p) {
            continue;
        }

        if (m_ship[id].last_attack != -1 && m_ship[id].last_attack + m_ship[id].r > cur_t) {
            v_wait.push_back({p, -id});
            continue;
        }

        psum += p;
        v_num.push_back({p, -id});
        m_ship[id].last_attack = cur_t;
    }

    for (int i = 0; i < v_wait.size(); i++) {
        pq.push({v_wait[i].first, v_wait[i].second});
    }

    for (int i = 0; i < v_num.size(); i++) {
        pq.push({v_num[i].first, v_num[i].second});
    }

    cout << psum << ' ' << v_num.size() << ' ';
    for (int i = 0; i < v_num.size(); i++) cout << v_num[i].second * -1 << ' ';
    cout << '\n';
}

int main() {
    // Please write your code here.
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while (cur_t < T) {
        cur_t++;
        int num;
        cin >> num;

        switch (num) {
            case 100:
                init();
                break;
            case 200:
                add();
                break;
            case 300:
                change();
                break;
            case 400:
                attack();
                break;
        }
    }

    return 0;
}
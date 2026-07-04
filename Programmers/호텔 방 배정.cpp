#include <string>
#include <unordered_map>
#include <vector>

typedef long long ll;

using namespace std;

unordered_map<ll, ll> parent;

ll find(ll x) {
    auto it = parent.find(x);
    if (it == parent.end()) return x;
    return it->second = find(it->second);
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    parent.reserve(room_number.size() * 2);

    for (ll target : room_number) {
        ll room = find(target);
        parent[room] = room + 1;
        answer.push_back(room);
    }

    return answer;
}
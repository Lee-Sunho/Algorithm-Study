#include <bits/stdc++.h>

using namespace std;

priority_queue<pair<int, int>> max_pq;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> min_pq;
vector<bool> is_pop;

vector<int> solution(vector<string> operations) {
    vector<int> answer;

    int id = 0;

    for (int i = 0; i < operations.size(); i++) {
        string command = operations[i];
        if (command[0] == 'I') {
            max_pq.push({stoi(command.substr(2)), id});
            min_pq.push({stoi(command.substr(2)), id});
            is_pop.push_back(false);
            id++;
        } else if (command == "D 1") {
            while (max_pq.size() && is_pop[max_pq.top().second]) {
                max_pq.pop();
            }
            if (max_pq.size()) {
                is_pop[max_pq.top().second] = true;
                max_pq.pop();
            }

        } else if (command == "D -1") {
            while (min_pq.size() && is_pop[min_pq.top().second]) {
                min_pq.pop();
            }
            if (min_pq.size()) {
                is_pop[min_pq.top().second] = true;
                min_pq.pop();
            }
        }
    }

    while (max_pq.size() && is_pop[max_pq.top().second]) {
        max_pq.pop();
    }

    while (min_pq.size() && is_pop[min_pq.top().second]) {
        min_pq.pop();
    }

    if (max_pq.size()) {
        answer.push_back(max_pq.top().first);
        answer.push_back(min_pq.top().first);
    } else {
        answer.push_back(0);
        answer.push_back(0);
    }

    return answer;
}
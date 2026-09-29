#include <bits/stdc++.h>

using namespace std;

priority_queue<int> pq;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    for (int i = 0; i < works.size(); i++) {
        pq.push(works[i]);
    }

    for (int i = 0; i < n; i++) {
        int max_value = pq.top();
        if (max_value == 0) break;
        pq.pop();
        max_value--;
        pq.push(max_value);
    }

    while (!pq.empty()) {
        answer += pow(pq.top(), 2);
        pq.pop();
    }

    return answer;
}
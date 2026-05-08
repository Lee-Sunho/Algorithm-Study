#include <bits/stdc++.h>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int time = 0;
    int sum = 0;
    queue<int> wait;
    queue<int> on_bridge;

    for (int i = 0; i < truck_weights.size(); i++) {
        wait.push(truck_weights[i]);
    }

    for (int i = 0; i < bridge_length; i++) {
        on_bridge.push(0);
    }

    while (!on_bridge.empty()) {
        time++;
        sum -= on_bridge.front();
        on_bridge.pop();

        if (!wait.empty()) {
            if (sum + wait.front() <= weight) {
                on_bridge.push(wait.front());
                sum += wait.front();
                wait.pop();
            } else {
                on_bridge.push(0);
            }
        }
    }
    return time;
}
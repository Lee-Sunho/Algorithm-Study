#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    vector<int> stk;

    for (int i = 0; i < prices.size(); i++) {
        while (!stk.empty() && prices[stk.back()] > prices[i]) {
            answer[stk.back()] = i - stk.back();
            stk.pop_back();
        }
        stk.push_back(i);
    }

    while (!stk.empty()) {
        answer[stk.back()] = prices.size() - stk.back() - 1;
        stk.pop_back();
    }
    return answer;
}
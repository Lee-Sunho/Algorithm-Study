#include <bits/stdc++.h>

using namespace std;

int cnt1, cnt2, cnt3;
vector<int> arr1 = {1, 2, 3, 4, 5};
vector<int> arr2 = {2, 1, 2, 3, 2, 4, 2, 5};
vector<int> arr3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    for (int i = 0; i < answers.size(); i++) {
        if (arr1[i % arr1.size()] == answers[i]) cnt1++;
        if (arr2[i % arr2.size()] == answers[i]) cnt2++;
        if (arr3[i % arr3.size()] == answers[i]) cnt3++;
    }

    int maxcnt = max({cnt1, cnt2, cnt3});
    if (maxcnt == cnt1) {
        answer.push_back(1);
    }

    if (maxcnt == cnt2) {
        answer.push_back(2);
    }

    if (maxcnt == cnt3) {
        answer.push_back(3);
    }

    return answer;
}
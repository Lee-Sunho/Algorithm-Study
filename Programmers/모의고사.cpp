#include <bits/stdc++.h>

using namespace std;

vector<int> arr1 = {1, 2, 3, 4, 5};
vector<int> arr2 = {2, 1, 2, 3, 2, 4, 2, 5};
vector<int> arr3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

int cnt1, cnt2, cnt3, max_cnt;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int n = answers.size();

    for (int i = 0; i < n; i++) {
        if (answers[i] == arr1[i % arr1.size()]) cnt1++;
        if (answers[i] == arr2[i % arr2.size()]) cnt2++;
        if (answers[i] == arr3[i % arr3.size()]) cnt3++;
    }

    max_cnt = max({cnt1, cnt2, cnt3});

    if (cnt1 == max_cnt) answer.push_back(1);
    if (cnt2 == max_cnt) answer.push_back(2);
    if (cnt3 == max_cnt) answer.push_back(3);

    return answer;
}
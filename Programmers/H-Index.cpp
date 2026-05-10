#include <bits/stdc++.h>

using namespace std;

bool comp(int a, int b) {
    return a > b;
}

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end(), comp);

    for (int i = 0; i < citations.size(); i++) {
        if (i >= citations[i]) return i;
    }

    return citations.size();
}
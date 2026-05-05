#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> nums) {
    int n = nums.size() / 2;
    unordered_set<int> s(nums.begin(), nums.end());

    return min((int)s.size(), n);
}
#include <bits/stdc++.h>

using namespace std;

int n, answer;

void func(int start, int sum, vector<int>& numbers, int target) {
    if (start == n) {
        if (sum == target) answer++;
        return;
    }

    func(start + 1, sum + numbers[start], numbers, target);
    func(start + 1, sum - numbers[start], numbers, target);
}

int solution(vector<int> numbers, int target) {
    n = numbers.size();
    func(0, 0, numbers, target);
    return answer;
}
#include <bits/stdc++.h>

using namespace std;

int answer = 0;
int g_target;
vector<int> g_numbers;

void func(int i, int sum) {
    if (i == g_numbers.size()) {
        if (sum == g_target) answer++;
        return;
    }

    func(i + 1, sum - g_numbers[i]);
    func(i + 1, sum + g_numbers[i]);
}

int solution(vector<int> numbers, int target) {
    g_numbers = numbers;
    g_target = target;

    func(0, 0);

    return answer;
}
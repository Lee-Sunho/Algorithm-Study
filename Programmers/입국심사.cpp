#include <bits/stdc++.h>

using namespace std;

long long solution(int n, vector<int> times) {
    sort(times.begin(), times.end());

    long long left = 0;
    long long right = (long long)times[times.size() - 1] * n;
    long long mid;
    long long answer;

    while (left <= right) {
        mid = (left + right) / 2;
        // cout << left << " " << right << " " << mid << " ";
        // mid 시간동안 심사위원 각각 심사할 수 있는 사람 수 합계 구하기
        long long sum = 0;
        for (int i = 0; i < times.size(); i++) {
            sum += (mid / times[i]);
        }
        // cout << sum << "\n";
        if (sum >= n) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return answer;
}
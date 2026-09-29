#include <bits/stdc++.h>

using namespace std;

bool isPrime[1000004];

int solution(int n) {
    int answer = 0;

    memset(isPrime, true, sizeof(isPrime));

    for (int i = 2; i <= (int)sqrt(n); i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) answer++;
    }

    return answer;
}
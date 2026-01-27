#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    while (scanf("%d", &n) != EOF) {
        long long target = 1, cnt = 1;
        while (1) {
            if (target % n == 0) {
                printf("%lld\n", cnt);
                break;
            } else {
                target = (target * 10) % n + 1;  // 1 % n
                cnt++;
            }
        }
    }

    return 0;
}
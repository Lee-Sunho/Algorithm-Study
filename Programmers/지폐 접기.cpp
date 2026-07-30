#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    int max_wallet, min_wallet;

    if (wallet[0] > wallet[1]) {
        max_wallet = wallet[0];
        min_wallet = wallet[1];
    } else {
        max_wallet = wallet[1];
        min_wallet = wallet[0];
    }

    while (1) {
        if (bill[0] > bill[1]) {
            if (bill[0] > max_wallet || bill[1] > min_wallet) {
                bill[0] /= 2;
                answer++;
            } else {
                break;
            }
        } else {
            if (bill[1] > max_wallet || bill[0] > min_wallet) {
                bill[1] /= 2;
                answer++;
            } else {
                break;
            }
        }
    }

    return answer;
}
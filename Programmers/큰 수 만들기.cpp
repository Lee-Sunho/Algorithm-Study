#include <bits/stdc++.h>

using namespace std;

string solution(string number, int k) {
    string answer = "";

    for (int i = 0; i < number.size(); i++) {
        while (!answer.empty() && answer.back() < number[i] && k > 0) {
            answer.pop_back();
            k--;
        }
        answer.push_back(number[i]);
    }

    while (k > 0) {
        answer.pop_back();
        k--;
    }

    return answer;
}
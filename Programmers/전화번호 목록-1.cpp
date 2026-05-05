// 해시를 이용한 방법
#include <bits/stdc++.h>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_set<string> s;

    for (string str : phone_book) {
        s.insert(str);
    }

    for (string str : phone_book) {
        string temp = "";
        for (int i = 0; i < str.length() - 1; i++) {
            temp += str[i];
            if (s.find(temp) != s.end()) return false;
        }
    }

    return true;
}
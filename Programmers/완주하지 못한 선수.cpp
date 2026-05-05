#include <bits/stdc++.h>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    int flag = 0;
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    for (int i = 0; i < completion.size(); i++) {
        if (participant[i].compare(completion[i]) != 0) {
            answer = participant[i];
            flag = 1;
            break;
        }
    }

    if (!flag) {
        answer = participant[participant.size() - 1];
    }

    return answer;
}
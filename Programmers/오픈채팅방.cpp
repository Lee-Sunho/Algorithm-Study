#include <bits/stdc++.h>

using namespace std;

vector<string> split(const string& input, const string& delimeter) {
    vector<string> temp;
    int start = 0;
    int end = input.find(delimeter);

    while (end != string::npos) {
        temp.push_back(input.substr(start, end - start));
        start = end + delimeter.size();
        end = input.find(delimeter, start);
    }
    temp.push_back(input.substr(start));
    return temp;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<vector<string>> log;
    unordered_map<string, string> nickname;

    for (int i = 0; i < record.size(); i++) {
        string str = record[i];
        vector<string> cmd = split(str, " ");
        if (cmd.size() == 3) {
            nickname[cmd[1]] = cmd[2];
        }
        log.push_back(cmd);
    }

    for (int i = 0; i < log.size(); i++) {
        string str = nickname[log[i][1]];
        if (log[i][0] == "Enter") {
            str += "님이 들어왔습니다.";
            answer.push_back(str);
        } else if (log[i][0] == "Leave") {
            str += "님이 나갔습니다.";
            answer.push_back(str);
        }
    }

    return answer;
}
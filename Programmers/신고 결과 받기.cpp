#include <bits/stdc++.h>

using namespace std;

// report 리스트를 set<string>으로 관리해서 중복 신고를 제거
// 신고 당한 map unordered_map<pair<string, int>>
// 신고한 배열 vector<vector<string>>;

set<string> report_set;
unordered_map<string, int> mmap;             // 신고당한
unordered_map<string, vector<string>> nmap;  // 신고한

vector<string> split(string input, string delimeter) {
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

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    int n = id_list.size();
    vector<int> answer(n, 0);

    for (int i = 0; i < report.size(); i++) {
        report_set.insert(report[i]);
    }

    for (string s : report_set) {
        vector<string> temp = split(s, " ");
        nmap[temp[0]].push_back(temp[1]);
        mmap[temp[1]]++;
    }

    for (int i = 0; i < id_list.size(); i++) {
        for (int j = 0; j < nmap[id_list[i]].size(); j++) {
            string target = nmap[id_list[i]][j];
            if (mmap[target] >= k) {
                answer[i]++;
            }
        }
    }

    return answer;
}
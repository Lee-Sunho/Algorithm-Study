#include <bits/stdc++.h>

using namespace std;

vector<int> answer;
vector<vector<int>> v;
bool visited[100001];

bool cmp(vector<int>& a, vector<int>& b) {
    return a.size() < b.size();
}

vector<int> solution(string s) {
    // 집합 별로 vector에 담은 다음에, 크기 순 오름차순 정렬
    // visited 배열 만든 후, 하나씩 정답 배열에 푸시
    int cur = 0;
    bool isOpen = false;
    vector<int> temp;
    for (int i = 1; i < s.size() - 1; i++) {  // 양 끝 괄호 무시
        if (s[i] == '{') {
            isOpen = true;
        } else if (s[i] == '}') {
            isOpen = false;
            temp.push_back(cur);
            v.push_back(temp);
            cur = 0;
            temp.clear();
        } else if (s[i] == ',') {
            if (isOpen) {
                temp.push_back(cur);
                cur = 0;
            }
        } else {  // 숫자인 경우
            cur = cur * 10 + (s[i] - '0');
        }
    }

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            if (!visited[v[i][j]]) {
                visited[v[i][j]] = true;
                answer.push_back(v[i][j]);
            }
        }
    }

    return answer;
}
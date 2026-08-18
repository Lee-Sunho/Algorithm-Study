#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int idx, sort_idx;

bool cmp(vector<int>& a, vector<int>& b) {
    return a[sort_idx] < b[sort_idx];
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;

    if (ext == "code") {
        idx = 0;
    } else if (ext == "date") {
        idx = 1;
    } else if (ext == "maximum") {
        idx = 2;
    } else {
        idx = 3;
    }

    if (sort_by == "code") {
        sort_idx = 0;
    } else if (sort_by == "date") {
        sort_idx = 1;
    } else if (sort_by == "maximum") {
        sort_idx = 2;
    } else {
        sort_idx = 3;
    }

    for (int i = 0; i < data.size(); i++) {
        if (data[i][idx] < val_ext) answer.push_back(data[i]);
    }

    sort(answer.begin(), answer.end(), cmp);

    return answer;
}
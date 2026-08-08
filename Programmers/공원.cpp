#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {
    sort(mats.rbegin(), mats.rend());

    for (int width : mats) {
        for (int i = 0; i < park.size(); i++) {
            for (int j = 0; j < park[0].size(); j++) {
                if (park[i][j] == "-1") {
                    bool flag = true;
                    for (int y = i; y < i + width; y++) {
                        for (int x = j; x < j + width; x++) {
                            if (y >= park.size() || x >= park[0].size() || park[y][x] != "-1") {
                                flag = false;
                                break;
                            }
                        }
                        if (!flag) break;
                    }
                    if (flag) return width;
                }
            }
        }
    }
    return -1;
}
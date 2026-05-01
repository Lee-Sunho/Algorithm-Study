#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0, w = 0, h = 0;

    for (int i = 0; i < sizes.size(); i++) {
        int longer = max(sizes[i][0], sizes[i][1]);
        int shorter = min(sizes[i][0], sizes[i][1]);

        w = max(w, longer);
        h = max(h, shorter);
    }
    answer = w * h;

    return answer;
}
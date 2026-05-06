#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int day = 0;
    int cnt = 0;
    int cur = -1;

    for (int i = 0; i < progresses.size(); i++) {
        if (cur >= i) continue;

        while (progresses[i] < 100) {
            day++;
            progresses[i] += speeds[i];
        }
        cur = i;
        cnt++;

        for (int j = i + 1; j < progresses.size(); j++) {
            progresses[j] += day * speeds[j];
            if (progresses[j] >= 100 && cur == j - 1) {
                cnt++;
                cur = j;
            }
        }
        answer.push_back(cnt);
        cnt = 0;
        day = 0;
    }

    return answer;
}
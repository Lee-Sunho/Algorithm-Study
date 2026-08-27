#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer(2, 0);
    int n = sequence.size();
    int min_len = 1e9;
    int start = 0;
    int sum = sequence[0];

    int l = 0, r = 0;
    while (r < n) {
        if (sum == k) {
            if (r - l < min_len) {
                answer[0] = l;
                answer[1] = r;
                min_len = r - l;
            }
            sum -= sequence[l++];
        } else if (sum < k) {
            r++;
            if (r < n) sum += sequence[r];
        } else {
            sum -= sequence[l++];
        }
    }

    return answer;
}
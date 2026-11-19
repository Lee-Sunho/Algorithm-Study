/*
카운팅 배열을 사용하는 방법
정렬과 비교했을 때 실행시간 50ms 차이
시간복잡도: O(k * NlogN) vs O(K + H)
덤프 1회 당: O(NlogN) vs O(N)
*/

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
    int test_case;
    // int T;

    // cin>>T;
    /*
       여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
    */
    for (test_case = 1; test_case <= 10; ++test_case) {  // 10
        int k, n = 100;
        cin >> k;

        vector<int> heights(101, 0);
        for (int i = 0; i < n; i++) {  // 100
            int x;
            cin >> x;
            heights[x]++;
        }

        int left = 1, right = 100;
        while (heights[left] == 0) left++;
        while (heights[right] == 0) right--;

        int gap = right - left;

        while (k-- && gap > 1) {
            heights[left]--;
            heights[left + 1]++;
            heights[right]--;
            heights[right - 1]++;

            while (heights[left] == 0) left++;
            while (heights[right] == 0) right--;
            gap = right - left;
        }

        cout << "#" << test_case << ' ' << gap << '\n';
    }
    return 0;  // 정상종료시 반드시 0을 리턴해야합니다.
}
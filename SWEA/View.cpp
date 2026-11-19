#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
    int test_case;
    // int T;

    // cin >> T;
    // /*
    //    여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
    // */
    for (test_case = 1; test_case <= 10; ++test_case) {
        int n;
        cin >> n;

        vector<int> v;
        for (int i = 0; i < n; i++) {
            int h;
            cin >> h;
            v.push_back(h);
        }

        int sum = 0;
        for (int i = 2; i < n - 2; i++) {
            int cmp = max({v[i - 2], v[i - 1], v[i + 1], v[i + 2]});
            if (v[i] > cmp) sum += (v[i] - cmp);
        }
        cout << "#" << test_case << ' ' << sum << '\n';
    }
    return 0;  // 정상종료시 반드시 0을 리턴해야합니다.
}
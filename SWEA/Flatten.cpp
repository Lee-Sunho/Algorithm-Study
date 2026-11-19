#include <algorithm>
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

        vector<int> v;
        for (int i = 0; i < n; i++) {  // 100
            int x;
            cin >> x;
            v.push_back(x);
        }

        sort(v.begin(), v.end());  // 100
        int gap = v[n - 1] - v[0];
        while (k-- && gap > 1) {  // 100
            v[n - 1]--;
            v[0]++;
            sort(v.begin(), v.end());
            gap = v[n - 1] - v[0];
        }

        cout << "#" << test_case << ' ' << v[n - 1] - v[0] << '\n';
    }
    return 0;  // 정상종료시 반드시 0을 리턴해야합니다.
}
#include <bits/stdc++.h>

using namespace std;

pair<int, int> l_point = {3, 0};
pair<int, int> r_point = {3, 2};

string solution(vector<int> numbers, string hand) {
    string answer = "";

    for (int i = 0; i < numbers.size(); i++) {
        int num = numbers[i];
        if (num % 3 == 1) {
            answer.push_back('L');
            l_point.first = num / 3;
            l_point.second = 0;
        } else if (num != 0 && num % 3 == 0) {
            answer.push_back('R');
            r_point.first = (num / 3) - 1;
            r_point.second = 2;
        } else {
            // cout << i << '\n';
            int y_num = (num == 0) ? 3 : (num / 3);
            int x_num = 1;
            // cout << y_num << ' ' << x_num << '\n';

            int l_dist = abs(l_point.first - y_num) + abs(l_point.second - x_num);
            int r_dist = abs(r_point.first - y_num) + abs(r_point.second - x_num);

            // if (i == 1) {
            //     cout << l_dist << ' ' << r_dist;
            // }

            if (l_dist == r_dist) {
                if (hand == "left") {
                    answer.push_back('L');
                    l_point.first = y_num;
                    l_point.second = x_num;
                } else {
                    answer.push_back('R');
                    r_point.first = y_num;
                    r_point.second = x_num;
                }
            } else if (l_dist < r_dist) {
                answer.push_back('L');
                l_point.first = y_num;
                l_point.second = x_num;
            } else {
                answer.push_back('R');
                r_point.first = y_num;
                r_point.second = x_num;
            }
        }
    }

    return answer;
}
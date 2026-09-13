#include <bits/stdc++.h>

using namespace std;

int changeTimeToInt(string str) {
    string s_hour = str.substr(0, 2);
    string s_minute = str.substr(3);

    if (s_hour[0] == '0') s_hour = s_hour.substr(1);
    if (s_minute[0] == '0') s_minute = s_minute.substr(1);

    int hour = stoi(s_hour);
    int minute = stoi(s_minute);

    return hour * 60 + minute;
}

string changeIntToTime(int num) {
    string hour = to_string(num / 60);
    string minute = to_string(num % 60);

    if (hour.size() != 2) hour = "0" + hour;
    if (minute.size() != 2) minute = "0" + minute;

    string str;
    str += (hour);
    str += (":");
    str += (minute);
    return str;
}

string solution(string video_len, string pos, string op_start, string op_end,
                vector<string> commands) {
    int i_pos = changeTimeToInt(pos);
    int i_vlen = changeTimeToInt(video_len);
    int i_opstart = changeTimeToInt(op_start);
    int i_opend = changeTimeToInt(op_end);

    for (int i = 0; i < commands.size(); i++) {
        string cmd = commands[i];

        // prev인 경우
        if (cmd == "prev") {
            // 현재 위치가 오프닝 중인 경우
            if (i_pos >= i_opstart && i_pos < i_opend) {
                i_pos = i_opend;
            }

            i_pos -= 10;
            if (i_pos >= i_opstart && i_pos < i_opend) {
                i_pos = i_opend;
            } else {
                i_pos = max(i_pos, 0);
            }
        }

        // next인 경우
        else if (cmd == "next") {
            // 현재 위치가 오프닝 중인 경우
            if (i_pos >= i_opstart && i_pos < i_opend) {
                i_pos = i_opend;
            }

            i_pos += 10;
            if (i_pos >= i_opstart && i_pos < i_opend) {
                i_pos = i_opend;
            } else {
                i_pos = min(i_pos, i_vlen);
            }
        }
    }
    return changeIntToTime(i_pos);
}
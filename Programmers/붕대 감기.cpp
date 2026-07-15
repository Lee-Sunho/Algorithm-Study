#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int t = attacks[attacks.size() - 1][0];
    int sec = 0;
    int success = 0;
    int idx = 0;
    int cur_health = health;

    while (sec <= t && cur_health > 0) {
        if (attacks[idx][0] == sec) {
            cur_health -= attacks[idx][1];
            success = 0;
            idx++;
        } else {
            cur_health = min(health, cur_health + bandage[1]);
            success++;

            if (success == bandage[0]) {
                cur_health = min(health, cur_health + bandage[2]);
                success = 0;
            }
        }
        sec++;
    }

    return cur_health > 0 ? cur_health : -1;
}
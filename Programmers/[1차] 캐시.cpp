#include <bits/stdc++.h>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    deque<string> cache;

    for (int i = 0; i < cities.size(); i++) {
        string city = cities[i];
        transform(city.begin(), city.end(), city.begin(), ::toupper);  // 대소문자 구분 x
        auto it = find(cache.begin(), cache.end(), city);

        if (it != cache.end()) {  // 캐시 적중
            cache.erase(it);
            cache.push_back(city);
            answer++;
        } else {                              // 캐시에 없는 경우
            if (cache.size() >= cacheSize) {  // 캐시 꽉 찬 경우
                if (!cache.empty()) {         // cacheSize가 0이 아닐때만
                    cache.pop_front();
                    cache.push_back(city);
                }
            } else {  // 캐시 안 찬 경우
                cache.push_back(city);
            }
            answer += 5;
        }
    }

    return answer;
}
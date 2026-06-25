#include <string>
#include <vector>

using namespace std;

char alpha[5] = {'A', 'E', 'I', 'O', 'U'};
int ret, cnt;

void func(string s, string word) {
    if (s.size() > 5) return;
    if (s == word) ret = cnt;

    cnt++;
    for (int i = 0; i < 5; i++) {
        func(s + alpha[i], word);
    }
}

int solution(string word) {
    func("", word);
    return ret;
}
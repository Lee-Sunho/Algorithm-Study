#include <bits/stdc++.h>

using namespace std;
vector<int> v;
unordered_set<int> s;
string str;
int visited[8];
int answer = 0;

bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}

void func(int idx, int n) {
    if (str.length() == n) return;
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        string temp = str;
        visited[i] = 1;
        str += v[i];
        s.insert(stoi(str));
        func(idx + 1, n);
        str = temp;
        visited[i] = 0;
    }
}

int solution(string numbers) {
    for (int i = 0; i < numbers.length(); i++) {
        v.push_back(numbers[i]);
    }

    func(0, numbers.length());

    for (int num : s) {
        if (isPrime(num)) answer++;
    }
    return answer;
}
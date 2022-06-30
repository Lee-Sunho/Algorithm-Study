#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool desc(int a, int b){
    return a > b;
}

int alpha[26] = {0, };

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<string> v;
    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        v.push_back(str);
    }

    for(string x: v){
        for(int i = 0; i < x.length(); i++){
            int digit = x.length() - i;
            int value = 1;
            for(int j = 0; j < digit - 1; j++){
                value *= 10; 
            }
            alpha[x[i] - 'A'] += value;
        }
    }

    sort(alpha, alpha + 26, desc);

    int num = 9;
    int sum = 0;
    int i = 0;
    while(alpha[i] != 0){
        sum += alpha[i] * num;
        num --;
        i++;
    }
    cout << sum;
}

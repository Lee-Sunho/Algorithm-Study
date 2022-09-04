#include <bits/stdc++.h>
using namespace std;

vector<string> v;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        v.push_back(str);
    }

    for(int i = 0; i < n; i++){
        int sum = 0;
        int score = 0;
        for(int j = 0; j < v[i].length(); j++){
            if(v[i][j] == 'O'){
                score++;
            }
            else{
                score = 0;
            }
            sum += score;
        }
        cout << sum << '\n';
    }
}

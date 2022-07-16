#include <bits/stdc++.h>
using namespace std;

int m, n;
int sum;
vector<int> v;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> m;
    cin >> n;
    for(int i = m; i <= n; i++){
        bool check = true;
        if(i == 1)
            continue;
        for(int j = 2; j < i; j++){
            if(i % j == 0){
                check = false;
                break;
            }
        }
        if(check == true){
            v.push_back(i);
            sum += i;
        }
    }
    if(sum == 0){
        cout << "-1";
        return 0;
    }
    cout << sum << '\n';
    cout << v[0];
}

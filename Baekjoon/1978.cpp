#include <bits/stdc++.h>
using namespace std;

int n, cnt;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        bool check = true;
        if(num == 1)
            continue;
        for(int j = 2; j < num; j++){
            if(num % j == 0){
                check = false;
                break;
            }
        }
        if(check == true)
            cnt++;
    }
    cout << cnt;
}

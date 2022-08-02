#include <bits/stdc++.h>
using namespace std;

int ans;
int main(){
    int n, k;
    cin >> n >> k;

    while(1){
        int cnt = 0;
        int temp = n;
        while(temp > 0){
            if(temp % 2 == 1) cnt++;
            temp = temp / 2;
        }
        if(cnt <= k){
            cout << ans;
            return 0;
        }
        else{
            ans++;
            n++;
        }
    }
}

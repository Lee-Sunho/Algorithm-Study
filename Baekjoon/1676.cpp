#include <bits/stdc++.h>
using namespace std;

int n;
int cnt = 0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 5; i <= n; i *= 5){
        cnt += n / i;
    }
    cout << cnt;
}

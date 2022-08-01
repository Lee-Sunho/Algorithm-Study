#include <bits/stdc++.h>
using namespace std;

int main(){
    int x;
    cin >> x;

    int cnt = 0;
    for(int i = 0; i < 32; i++){
        if((x & (1 << i))) cnt++;
    }
    cout << cnt;
}

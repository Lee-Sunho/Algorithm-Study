#include <bits/stdc++.h>
using namespace std;

int n, r, c;

int func(int n, int r, int c){
    int half = 1<<(n-1);
    if(n == 0) return 0;
    if(r < 1<<(n-1) && c < 1<<(n-1)) return func(n-1, r, c);
    if(r < 1<<(n-1) && c >= 1<<(n-1)) return half * half + func(n-1, r, c-half);
    if(r >= 1<<(n-1) && c < 1<<(n-1)) return 2 * half * half + func(n-1, r-half, c);
    if(r >= 1<<(n-1) && c >= 1<<(n-1)) return 3 * half * half + func(n-1, r-half, c-half);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> r >> c;

    cout << func(n, r, c);
}

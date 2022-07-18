#include <bits/stdc++.h>
using namespace std;

int n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    if(n == 1){
        return 0;
    }
    int i = 2;
    while(n > 1){
        if(n % i == 0){
            cout << i << '\n';
            n = n / i;
        }
        else i++;
    }
}

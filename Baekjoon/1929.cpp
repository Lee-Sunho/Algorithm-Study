#include <bits/stdc++.h>
using namespace std;

int m, n;
int main(){
    cin >> m >> n;
    for(int i = m; i <= n; i++){
        bool check = true;
        if(i == 1)
            continue;
        for(int j = 2; j <= sqrt(i); j++){
            if(i % j == 0){
                check = false;
                break;
            }
        }
        if(check == true){
            cout << i << '\n';
        }
    }
}

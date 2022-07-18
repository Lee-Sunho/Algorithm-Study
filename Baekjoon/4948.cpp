#include <bits/stdc++.h>
using namespace std;
bool is_prime[250000];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    while(1){
        fill(is_prime, is_prime + 250000, true);
        cin >> n;
        if(n == 0) return 0;
        int cnt = 0;
        
        for(int i = 2; i <= 2*n; i++){
            if(is_prime[i] == false) continue;
            for(int j = i+i; j <= 2*n; j += i){
                is_prime[j] = false;
            }
        }

        for(int i = n+1; i <= 2*n; i++){
            if(is_prime[i] == true){
                cnt++;
            }
        }
        cout << cnt << '\n';
    }
}

#include <bits/stdc++.h>
using namespace std;

bool is_prime[10001];
int T;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    int n;
    for(int t = 0; t < T; t++){
        cin >> n;
        fill(is_prime, is_prime + n, true);
        vector<int> v_prime;
        vector<pair<int, int>> result;
        for(int i = 2; i <= sqrt(n); i++){
            if(is_prime[i] == false) continue;
            for(int j = i+i; j <= n; j += i){
                is_prime[j] = false;
            }
        }
        for(int i = 2; i <= n; i++){
            if(is_prime[i] == true){
                v_prime.push_back(i);
            }
        }

        for(auto itr1 = v_prime.begin(); itr1 != v_prime.end(); itr1++){
            for(auto itr2 = itr1; itr2 != v_prime.end(); itr2++){
                if(*itr1 + *itr2 == n){
                    result.push_back({*itr1, *itr2});
                }
            }
        }
        cout << result.back().first << " " << result.back().second << '\n';
    }
}

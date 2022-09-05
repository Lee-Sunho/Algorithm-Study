#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int dp[100006];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    v.push_back(0); // index 0 초기화
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    for(int i = 1; i <= n; i++){
        if(dp[i-1] + v[i] > v[i]){
            dp[i] = dp[i-1] + v[i];
        }
        else{
            dp[i] = v[i];
        }
    }
    cout << *max_element(dp + 1, dp+n+1);
}

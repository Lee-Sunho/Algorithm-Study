#include <bits/stdc++.h>
using namespace std;

vector<int> num;
int cnt;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        num.push_back(x);
    }

    int start = 0, end = 0;
    int partial_sum = num[0];
    while(end < n){
        if(partial_sum > m){
            partial_sum -= num[start];
            start++;
        }
        else if(partial_sum < m){
            end++;
            partial_sum += num[end];
        }
        else{
            cnt++;
            partial_sum -= num[start];
            start++;
            end++;
            if(end < n){
                partial_sum += num[end];
            }
        }
    }
    cout << cnt;
}

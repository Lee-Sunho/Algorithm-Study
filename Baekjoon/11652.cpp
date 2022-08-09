#include <bits/stdc++.h>
using namespace std;

long long maxvl;
long long maxcnt = 0;
long long arr[100002];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        long long num;
        cin >> num;
        arr[i] = num;
    }

    sort(arr, arr + n);

    long long temp = arr[0];
    maxvl = temp;
    int cnt = 1;
    for(int i = 1; i < n; i++){
        if(temp == arr[i]){
            cnt++;
        }
        else{
            if(cnt > maxcnt){
                maxcnt = cnt;
                maxvl = temp;
            }
            temp = arr[i];
            cnt = 1;
        }
    }
    if(cnt > maxcnt){
        maxcnt = cnt;
        maxvl = temp;
    }

    cout << maxvl;
}

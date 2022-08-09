#include <bits/stdc++.h>
using namespace std;

int cnt[2000002];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        cnt[num + 1000000]++;
    }

    for(int i = 0; i <= 2000000; i++){
        for(int j = 0; j < cnt[i]; j++){
            cout << i - 1000000 << '\n';
        }
    }
}

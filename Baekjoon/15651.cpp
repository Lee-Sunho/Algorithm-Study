#include <bits/stdc++.h>
using namespace std;

int *arr;
int n, m;

void dfs(int k){
    if(k == m){
        for(int i = 0; i < m; i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = 1; i <= n; i++){
        arr[k] = i;
        dfs(k + 1);
    }
}

int main(){
    cin >> n >> m;

    arr = (int*)malloc(sizeof(int) * m);
    dfs(0);
}

#include <bits/stdc++.h>
using namespace std;

int cnt = 0;
int n, m;
int graph[1001][1001];
bool dfs(int x, int y){
    if(x <= -1 || x >= n || y <= -1 || y >= m){
        return false;
    }
    if(graph[x][y] == 0){
        graph[x][y] = 1;
        dfs(x, y+1);
        dfs(x+1, y);
        return true;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%1d", &graph[i][j]);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(dfs(i, j)){
                cnt++;
            }
        }
    }
    cout << cnt;
}

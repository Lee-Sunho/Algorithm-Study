#include <bits/stdc++.h>
using namespace std;

int n, m;
int board[51][51];
vector<pair<pair<int, int>, bool>> chicken;
vector<pair<int, int>> selected;
vector<pair<int, int>> home;
int ans = 999999;

int dist(){
    int dist_sum = 0;
    for(int i = 0; i < home.size(); i++){
        int dist = 999999;
        for(int j = 0; j < selected.size(); j++){
            int temp = abs(home[i].first - selected[j].first) + abs(home[i].second - selected[j].second);
            dist = min(dist, temp);
        }
        dist_sum += dist;
    }
    return dist_sum;
}

void func(int cur, int index){
    if(cur == m){
        ans = min(ans, dist());
        return;
    }

    for(int i = index; i < chicken.size(); i++){
        if(chicken[i].second == false){
            chicken[i].second = true;
            selected.push_back(chicken[i].first);
            func(cur+1, i);
            chicken[i].second = false;
            selected.pop_back();
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
            if(board[i][j] == 1){
                home.push_back({i, j});
            }
            else if(board[i][j] == 2){
                chicken.push_back({{i, j}, false});
            }
        }
    }

    func(0, 0);
    cout << ans;
}

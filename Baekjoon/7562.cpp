#include <bits/stdc++.h>
using namespace std;
int T;
pair<int, int> mv[8] = {
    {-1, 2},
    {-1, -2},
    {-2, 1},
    {-2, -1},
    {1, 2},
    {1, -2},
    {2, 1},
    {2, -1}
};

int board[302][302];
queue<pair<int, int>> q;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    for(int t = 0; t < T; t++){
        int check = 0;
        for(int i = 0; i < 302; i++){
            fill(board[i], board[i] + 301, -1);
        }
        int size, x_init, y_init, x_goal, y_goal;
        cin >> size;
        cin >> x_init >> y_init;
        cin >> x_goal >> y_goal;

        if(x_init == x_goal && y_init == y_goal){
            cout << "0" << '\n';
            continue;
        }

        board[x_init][y_init] = 0;
        q.push({x_init, y_init});
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int i = 0; i < 8; i++){
                int nx = x + mv[i].first;
                int ny = y + mv[i].second;

                if(nx < 0 || nx >= size || ny < 0 || ny >= size) continue;
                if(nx == x_goal && ny == y_goal){
                    board[nx][ny] = board[x][y] + 1;
                    check = 1;
                    break;
                }
                if(board[nx][ny] == -1){
                    board[nx][ny] = board[x][y] + 1;
                    q.push({nx, ny});
                }
            }

            if(check == 1){
                cout << board[x_goal][y_goal] << '\n';
                break;
            }
        }
        while(!q.empty()) q.pop();
    }
}

#include <iostream>
#include <queue>
using namespace std;

int n, m;
int board[501][501];
bool is_visited[501][501];
int cnt = 0;
int biggest = 0;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

queue<pair<int, int>> q;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int size = 0;
            if(board[i][j] == 1 && is_visited[i][j] == false){
                q.push(make_pair(i, j));
                is_visited[i][j] = true;
                size++;

                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    for(int i = 0; i < 4; i++){
                        int nx = x + dx[i];
                        int ny = y + dy[i];

                        if(nx < 0 || nx >= n || ny < 0 || ny >= m){
                            continue;
                        }

                        if(board[nx][ny] == 1 && is_visited[nx][ny] == false){
                            q.push(make_pair(nx, ny));
                            is_visited[nx][ny] = true;
                            size++;
                        }
                    }
                }
                if(size > biggest)
                    biggest = size;
                cnt++;
            }
        }
    }
    cout << cnt << '\n';
    cout << biggest;
}

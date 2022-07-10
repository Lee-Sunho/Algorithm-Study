#include <iostream>
#include <queue>
using namespace std;

int n, k;
int board[100002];
queue<int> q;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fill(board, board + 100001, -1);
    cin >> n >> k;
    board[n] = 0;
    q.push(n);
    while(board[k] == -1){
        int x = q.front();
        q.pop();

        for(int nx : {x-1, x+1, 2*x}){
            if(nx < 0 || nx > 100000)
                continue;
            if(board[nx] != -1)
                continue;
            board[nx] = board[x] + 1;
            q.push(nx);
        }
    }
    cout << board[k];
}

#include <iostream>
#include <vector>
using namespace std;

int cnt = 0;
bool flag = false;
int board[9][9] = {0, };
vector<pair<int, int>> blank;

bool check(int x, int y){
    int square_x = x % 3;
    int square_y = y % 3;

    for(int i = 0; i < 9; i++){
        if(board[x][i] == board[x][y] && i != y)
            return false;
        if(board[i][y] == board[x][y] && i != x)
            return false;
    }

    for(int i = x - square_x; i < x - square_x + 3; i++){
        for(int j = y - square_y; j < y - square_y + 3; j++){
            if(i == x && j == y)
                continue;
                
            if(board[i][j] == board[x][y])
                return false;
        }
    }
    return true;
}

void func(int n){
    if(n == cnt){
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                cout << board[i][j] << ' ';
            }
            cout << '\n';
        }
        flag = true;
        return;
    }
    int x = blank[n].first;
    int y = blank[n].second;

    for(int i = 1; i <= 9; i++){
        board[x][y] = i;
        if(check(x, y)){
            func(n+1);
        }
        if(flag)
            return;
    }
    board[x][y] = 0;
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cin >> board[i][j];
            if(board[i][j] == 0){
                blank.push_back(make_pair(i, j));
                cnt++;
            }
        }
    }
    func(0);
}

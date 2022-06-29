#include <iostream>
using namespace std;

char arr[51][51];
char w_board[8][8] = {
    'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
    'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
    'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
    'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
    'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
    'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
    'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
    'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'
};

char b_board[8][8] = {
    'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
    'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
    'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
    'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
    'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
    'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
    'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
    'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }

    int min = 99;
    int b_cnt = 0, w_cnt = 0;
    for(int x = 0; x < n-7; x++){
        for(int y = 0; y < m-7; y++){
            for(int i = 0; i < 8; i++){
                for(int j = 0; j < 8; j++){
                    if(arr[x + i][y + j] != b_board[i][j])
                        b_cnt++;
                    
                    if(arr[x + i][y + j] != w_board[i][j])
                        w_cnt++;
                }
            }
            int result = (b_cnt < w_cnt) ? b_cnt : w_cnt;
            if(result < min)
                min = result;
            b_cnt = 0;
            w_cnt = 0;
        }
    }
    cout << min;
}

#include <iostream>
using namespace std;

int n, cnt = 0;
int col[14];

bool check(int cur){
    for(int i = 0; i < cur; i++){
        if(col[i] == col[cur] || cur - i == abs(col[cur] - col[i])){
            return false;
        }
    }
    return true;
}

void func(int cur){
    if(cur == n){
        cnt++;
        return;
    }
    for(int i = 0; i < n; i++){
        col[cur] = i;
        if(check(cur))
            func(cur+1);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    func(0);
    cout << cnt;
}

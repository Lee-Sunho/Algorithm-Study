#include <iostream>
#include <vector>
using namespace std;

int cnt = 0;
int n, s;
vector<int> v;
void dfs(int cur, int sum){
    if(cur == n){
        if(sum == s){
            cnt++;
        }
        return;
    }
    dfs(cur+1, sum);
    dfs(cur+1, sum + v[cur]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> s;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    dfs(0, 0);

    if(s == 0){
        cnt --;
    }
    cout << cnt;
}

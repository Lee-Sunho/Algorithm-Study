#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int compare(pair<int, int> a, pair<int, int> b){
    if(a.first < b.first && a.second < b.second){
        return 1;
    }
    else
        return 0;
}

int main(){
    int n;
    cin >> n;

    int x, y;
    vector<pair<int, int>> v;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }

    for(int i = 0; i < n; i++){
        int cnt = 1;
        for(int j = 0; j < n; j++){
            if(i == j){
                continue;
            }
            if(compare(v[i], v[j]) == 1){
                cnt++;
            }
        }
        cout << cnt << " ";
    }
}

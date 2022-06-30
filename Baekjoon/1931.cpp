#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    else
        return a.second < b.second;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> v;
    for(int i = 0; i < n; i++){
        int start, end;
        cin >> start >> end;
        v.push_back(make_pair(start, end));
    }
    sort(v.begin(), v.end(), compare);
    
    int cnt = 0;
    int t_end = 0;
    for(int i = 0; i < n; i++){
        if(t_end <= v[i].first){
            cnt++;
            t_end = v[i].second;
        }
    }
    cout << cnt;
}

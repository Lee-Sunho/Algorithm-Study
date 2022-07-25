#include<bits/stdc++.h>
using namespace std;

vector<int> arr;
vector<int> idx;
int cnt;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w;
    cin >> h >> w;

    for(int i = 0; i < w; i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }

    int top = *max_element(arr.begin(), arr.end());
    for(int i = top; i > 0; i--){
        for(int j = 0; j < w; j++){
            if(arr[j] >= i){
                idx.push_back(j);
            }
        }
        
        if(idx.size() > 1){
            for(int k = 0; k < idx.size()-1; k++){
                cnt += idx[k+1] - idx[k] - 1;
            }
        }
        while(!idx.empty()){
            idx.pop_back();
        }
    }
    cout << cnt;
}

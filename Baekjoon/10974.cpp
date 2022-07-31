#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> v;
    for(int i = 1; i <= n; i++){
        v.push_back(i);
    }

    do{
        for(int i = 0; i < v.size(); i++){
            cout << v[i] << ' ';
        }
        cout << '\n';
    } while(next_permutation(v.begin(), v.end()));
    return 0;
}

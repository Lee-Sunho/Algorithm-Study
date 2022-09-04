#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for(int i = 0; i < 8; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }

    bool ascending = true;
    bool descending = true;

    for(int i = 0; i < 7; i++){
        if(v[i] > v[i+1]) ascending = false;
        else if(v[i] < v[i+1]) descending = false;
    }

    if(ascending) cout << "ascending";
    else if(descending) cout << "descending";
    else cout << "mixed";
}

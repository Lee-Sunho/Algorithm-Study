#include <bits/stdc++.h>
using namespace std;

vector<string> v;

bool compare(string &x, string &y){
    if(x.length() == y.length()){
        return x < y;
    }
    else{
        return x.length() < y.length();
    }

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        v.push_back(str);
    }

    sort(v.begin(), v.end(), compare);
    v.erase(unique(v.begin(), v.end()), v.end());
    for(string str: v){
        cout << str << '\n';
    }
}

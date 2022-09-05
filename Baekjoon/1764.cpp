#include <bits/stdc++.h>
using namespace std;

vector<string> v1;
vector<string> v2;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        v1.push_back(str);
    }

    for(int i = 0; i < m; i++){
        string str;
        cin >> str;
        v2.push_back(str);
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    vector<string> result(v1.size() + v2.size());
    auto iter = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), result.begin());
    result.erase(iter, result.end());

    cout << result.size() << '\n';
    for(string str: result) cout << str << '\n';
}

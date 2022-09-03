#include <bits/stdc++.h>
using namespace std;

vector<pair<string, int>> v;
string arr[100006];

int binary_search(int left, int right, string str){
    while(left <= right){
        int mid = (left + right) / 2;
        if(v[mid].first == str) return v[mid].second;
        else if(v[mid].first < str) left = mid + 1;
        else right = mid - 1;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        string str;
        cin >> str;
        arr[i] = str;
        v.push_back({str, i});
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < m; i++){
        string input;
        cin >> input;

        if(isdigit(input[0]) == 0){
            cout << binary_search(0, n, input) << '\n';
        }
        else{
            cout << arr[stoi(input)] << '\n';
        }
    }
}

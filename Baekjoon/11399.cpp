#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> v;
    for(int i = 0; i < n; i++){
        int time;
        cin >> time;
        v.push_back(time);
    }

    sort(v.begin(), v.end());
    int sum = 0;
    int waiting = 0;
    for(int i : v){
        sum += waiting + i;
        waiting += i;
    }
    cout << sum;
}

#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;

    string key = "666";
    int cnt = 1;
    int num = 666;
    while(cnt < n){
        num++;
        string str = to_string(num);
        if(str.find(key) != -1){
            cnt++;
        }
    }
    cout << num;
}

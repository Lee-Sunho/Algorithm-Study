#include <iostream>
using namespace std;

int main(){
    int n, cnt = 0;
    cin >> n;

    if(n % 5 == 0){
        cout << n / 5;
        return 0;
    }
    while(n > 0){
        n -= 3;
        cnt++;
        if(n % 5 == 0){
            cout << cnt + n / 5;
            return 0;
        }
    }
    cout << "-1";
}

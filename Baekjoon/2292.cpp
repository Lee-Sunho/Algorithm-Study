#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    if(n == 1){
        cout << 1;
        return 0;
    }

    if(n >= 2 && n <= 7){
        cout << 2;
        return 0;
    }

    int cnt = 2;
    int sum = 1;
    for(int i = 1;; i++){
        sum += 6 * i;
        if(n > sum){
            cnt++;
        }
        else{
            cout << cnt;
            break;
        }
    }
}

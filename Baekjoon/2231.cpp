#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    for(int num = 0; num < n; num++){
        int ans = 0;
        int temp = num;
        ans += temp;

        while(temp >= 10){
            ans += temp % 10;
            temp = temp / 10;
        }
        ans += temp;
        if(ans == n){
            cout << num << endl;
            return 0;
        }
    }
    cout << "0" << endl;
}

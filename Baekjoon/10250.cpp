#include <iostream>
using namespace std;

int main(){
    int t, h, w, n;
    int floor, num;
    cin >> t;

    for(int i = 0; i < t; i++){
        cin >> h >> w >> n;

        if(n % h == 0){
            floor = h;
            num = n / h;
        }
        else{
            floor = n % h;
            num = n / h + 1;
        }

        if(num < 10){
            cout << floor << "0" << num << "\n";
        }
        else{
            cout << floor << num << "\n";
        }
    }
}

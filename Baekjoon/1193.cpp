#include <iostream>
using namespace std;

int main(){
    int x;
    cin >> x;

    if(x == 1){
        cout << 1 << "/" << 1;
        return 0;
    }

    int n = 1;
    int i = 2;
    while(1){
        int a, b;
        int max = n + i;
        if(x <= max){
            int diff = max - x;
            if(i % 2 == 1){
                a = 1 + diff;
                b = i - diff;
            }
            else{
                a = i - diff;
                b = 1 + diff;
            }

            cout << a << "/" << b;
            break;
        }
        n = max;
        i++;
    }
}

#include <iostream>
using namespace std;

int a, b, c;

long long func(int a, int b, int c){
    if(b == 0)
        return 1;
    if(b == 1)
        return a % c;

    long long k = func(a, b/2, c);
    if(b % 2 == 0)
        return k * k % c;
    else
        return k * k % c * a % c;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> a >> b >> c;

    cout << func(a, b, c);
}

#include <iostream>
using namespace std;

int main(){
    int a, b, c;
    long long n;
    cin >> a >> b >> c;

    if(b >= c){
        printf("-1");
    }
    else{
        n = a / (c - b) + 1;
        printf("%lld", n);
    }
}

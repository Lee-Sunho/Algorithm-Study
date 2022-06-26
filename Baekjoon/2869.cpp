#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int a, b, v;
    int cnt = 1;
    cin >> a >> b >> v;

    if(a == v){
        cout << cnt;
        return 0;
    }
    
    if((v-a) % (a-b) == 0){
        cnt += (v-a) / (a-b);
        cout << cnt;
    }

    else{
        cnt += (v-a) / (a-b) + 1;
        cout << cnt;
    }
    
}

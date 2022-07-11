#include <iostream>
using namespace std;

int n;

void func(int a, int b, int cnt){
    if(cnt == 1){
        cout << a << " " << b << '\n';
        return;
    }
    func(a, 6-a-b, cnt-1);
    cout << a << " " << b << '\n';
    func(6-a-b, b, cnt-1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
 
    cout << (1<<n) - 1 << '\n';
    func(1, 3, n);
}

#include <bits/stdc++.h>
using namespace std;

int s;
void add(int x){
    s |= (1 << x);
}
void remove(int x){
    s &= ~(1 << x);
}
void check(int x){
    if(s & (1 << x)) cout << "1" << '\n';
    else cout << "0" << '\n';
}
void toggle(int x){
    s ^= (1 << x);
}
void all(){
    s = (1 << 21) - 1;
}
void empty(){
    s = 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> m;

    for(int i = 0; i < m; i++){
        string op;
        cin >> op;
        if(op == "add"){
            int x;
            cin >> x;
            add(x);
        }
        else if(op == "remove"){
            int x;
            cin >> x;
            remove(x);
        }
        else if(op == "check"){
            int x;
            cin >> x;
            check(x);
        }
        else if(op == "toggle"){
            int x;
            cin >> x;
            toggle(x);
        }
        else if(op == "all"){
            all();
        }
        else if(op == "empty"){
            empty();
        }
    }
}

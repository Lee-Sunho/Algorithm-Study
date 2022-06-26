#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    string a, b;
    cin >> a >> b;

    int len_a = a.length();
    int len_b = b.length();

    if(len_a > len_b){
        for(;len_b < len_a; len_b++){
            b = "0" + b;
        }
    }
    else{
        for(;len_a < len_b; len_a++){
            a = "0" + a;
        }
    }

    vector <int> ans;

    int idx = len_b - 1;
    int carry = 0;
    for(;idx >= 0; idx--){
        int num_a = a[idx] - '0';
        int num_b = b[idx] - '0';

        ans.push_back((num_a + num_b + carry) % 10);
        carry = (num_a + num_b + carry) / 10;
    }
    if(carry > 0)
        ans.push_back(carry);
    for(int i = ans.size() - 1; i >= 0; i--){
        cout << ans[i];
    }
}

#include <iostream>
#include <string>
using namespace std;

int main(){
    string alpha[8] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

    string input;
    cin >> input;

    for(int i = 0; i < 8; i++){
        while(1){
            int idx = input.find(alpha[i]);
            if(idx == -1){
                break;
            }
            input.replace(idx, alpha[i].length(), "#");
        }
    }
    cout << input.length();
}

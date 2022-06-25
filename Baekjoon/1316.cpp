#include <iostream>
#include <string>
using namespace std;

int main(){
    int num;
    cin >> num;

    int cnt = 0;
    string str;
    for(int i = 0; i < num; i++){
        cin >> str;
        int len = str.length();
        
        int check = 1;
        char c = str[0];
        for(int j = 1; j < len; j++){
            if(c != str[j]){
                for(int k = j - 2; k >= 0; k--){
                    if(str[k] == str[j]){
                        check = 0;
                        break;
                    }
                }
            }
            c = str[j];
        }
        if(check == 1){
            cnt += 1;
        }
    }
    cout << cnt;
}

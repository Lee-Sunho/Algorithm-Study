// 1062번 백트래킹, 비트마스킹 사용 버전
#include <bits/stdc++.h>
using namespace std;

int checked;
int word[50]; // n 최대 50
int n, k;
int result;

void func(int toPick, int start){
    if(toPick == 0){
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if((word[i] & checked) == word[i]) cnt++;
        }
        if(result < cnt) result = cnt;
        return;
    }

    for(int i = start; i < 26; i++){
        if((checked & (1 << i)) == 0){
            checked |= (1 << i);
            func(toPick-1, i);
            checked &= ~(1 << i);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    string str;
    for(int i = 0; i < n; i++){
        cin >> str;
        
        int num = 0;
        for(int j = 0; j < str.length(); j++){
            num |= 1 << (str[j] - 'a');
        }
        word[i] = num;
    }

    if(k < 5) cout << "0";
    else if(k == 26) cout << n;
    else{
        checked |= (1 << ('a' - 'a'));
        checked |= (1 << ('c' - 'a'));
        checked |= (1 << ('i' - 'a'));
        checked |= (1 << ('n' - 'a'));
        checked |= (1 << ('t' - 'a'));

        func(k-5, 0);
        cout << result;
    }
    return 0;
}

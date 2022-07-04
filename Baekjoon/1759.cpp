#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int L, C;
char arr[15];
char str[15];
bool is_used[15] = {false, };
char vowels[5] = {'a', 'e', 'i', 'o', 'u'};

bool check(int n, int num){
    if(is_used[num] == true)
        return false;
    for(int i = 0; i <= n; i++){
        if(str[i] > arr[num])
            return false;
    }
    return true;
}

void func(int n){
    if(n == L){
        int vowel_cnt = 0;
        for(int i = 0; i < L; i++){
            for(int j = 0; j < 5; j++){
                if(str[i] == vowels[j])
                    vowel_cnt++;
            }
        }
        if(vowel_cnt < 1 || L - vowel_cnt < 2)
            return;
        for(int i = 0; i < L; i++)
            cout << str[i];
        cout << '\n';
        return;
    }

    for(int i = 0; i < C; i++){
        str[n] = arr[i];
        if(check(n, i)){
            is_used[i] = true;
            func(n + 1);
            is_used[i] = false;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> L >> C;
    for(int i = 0; i < C; i++){
        cin >> arr[i];
    }
    sort(arr, arr + C);

    func(0);
}

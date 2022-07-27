#include <bits/stdc++.h>
using namespace std;

bool alpha[26] = {false, };
vector<string> words;
vector<char> new_alpha;
vector<int> results;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    for(int i = 0; i < n; i++){
        string word;
        cin >> word;
        words.push_back(word);
    }

    alpha['a' - 'a'] = true;
    alpha['c' - 'a'] = true;
    alpha['i' - 'a'] = true;
    alpha['n' - 'a'] = true;
    alpha['t' - 'a'] = true;

    int cnt = k - 5;
    if(cnt < 0){
        cout << "0";
        return 0;
    }

    for(string str: words){
        for(int i = 0; i < str.length(); i++){
            if(alpha[str[i] - 'a'] == false){
                new_alpha.push_back(str[i]);
            }
        }
    }

    sort(new_alpha.begin(), new_alpha.end());
    new_alpha.erase(unique(new_alpha.begin(), new_alpha.end()), new_alpha.end());
    
    vector<bool> v(new_alpha.size(), false);
    for(int i = 0; i < cnt; i++){
        v[i] = true;
    }

    do{
        vector<int> cn;
        for(int i = 0; i < new_alpha.size(); i++){
            if(v[i]){
                cn.push_back(i);
                alpha[new_alpha[i] - 'a'] = true;
            }
        }

        int sum = 0;
        for(int i = 0; i < n; i++){
            bool check = true;
            for(int j = 4; j < words[i].size(); j++){
                if(alpha[words[i][j] - 'a'] == false){
                    check = false;
                    break;
                }
            }
            if(check == true){
                sum++;
            }
        }
        results.push_back(sum);
        for(int i: cn){
            alpha[new_alpha[i] - 'a'] = false;
        }
        while(!cn.empty()) cn.pop_back();
    } while(prev_permutation(v.begin(), v.end()));

    cout << *max_element(results.begin(), results.end());
}

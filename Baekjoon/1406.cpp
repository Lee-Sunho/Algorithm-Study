#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    int m;

    cin >> str;
    cin >> m;

    list<char> list;
    for(int i = 0; i < str.length(); i++){
        list.push_back(str[i]);
    }

    std::list<char>::iterator itr = list.end();
    for(int i = 0; i < m; i++){
        string command;
        cin.ignore();
        cin >> command;

        switch (command[0]){
            case 'L':
                if(itr != list.begin())
                    itr --;
                break;
            case 'D':
                if(itr != list.end())
                    itr ++;
                break;
            case 'B':
                if(itr != list.begin()){
                    itr = list.erase(--itr);
                }
                break;
            case 'P':
                char target;
                cin >> target;
                list.insert(itr, target);
                break;
        }
    }

    for(std::list<char>::iterator itr = list.begin(); itr != list.end(); itr++){
            cout << *itr;
    } 
}

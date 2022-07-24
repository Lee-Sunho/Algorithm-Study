#include <iostream>
using namespace std;

int n;
int num[11];
int op[4];
int max_res = -100000001;
int min_res = 100000001;

void func(int cur, int res){
    if (cur == n){
        if(res > max_res){
            max_res = res;
        }
        if(res < min_res){
            min_res = res;
        }
        return;
    }

    for(int j = 0; j < 4; j++){
        if(op[j] != 0){
            op[j]--;
            switch (j){
                case 0:
                    func(cur+1, res + num[cur]);
                    op[j]++;
                    break;

                case 1:
                    func(cur+1, res - num[cur]);
                    op[j]++;
                    break;

                case 2:
                    func(cur+1, res * num[cur]);
                    op[j]++;
                    break;

                case 3:
                    func(cur+1, res / num[cur]);
                    op[j]++;
                    break;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> num[i];
    }

    for (int i = 0; i < 4; i++){
        cin >> op[i];
    }
    func(1, num[0]);
    cout << max_res << "\n";
    cout << min_res;
}

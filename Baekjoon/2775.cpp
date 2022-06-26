#include <iostream>
using namespace std;

int main(){
    int t, a, n;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> a;
        cin >> n;

        int arr[15][15] = {0,};
        for(int j = 0; j < 15; j++){
            for(int k = 1; k < 15; k++){
                if(j == 0){
                    arr[j][k] = k;
                }
                else{
                    arr[j][k] = arr[j - 1][k] + arr[j][k - 1];
                }
            }
        }
        cout << arr[a][n] << "\n";
    }
}

#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int *arr = (int *)malloc(sizeof(int) * n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int max = 0, sum = 0;
    for(int i = 0; i < n - 2; i++){
        for(int j = i + 1; j < n - 1; j++){
            for(int k = j + 1; k < n; k++){
                sum = arr[i] + arr[j] + arr[k];
                if(sum <= m && sum > max){
                    max = sum;
                }
            }
        }
    }
    cout << max << endl;
}

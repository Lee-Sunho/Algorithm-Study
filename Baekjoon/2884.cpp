#include <iostream>
using namespace std;

int main(){
    int hour, minute;
    cin >> hour >> minute;

    int new_hour, new_minute;
    if(minute - 45 < 0){
        new_minute = minute + 15;
        if(hour == 0){
            new_hour = 23;
        }
        else new_hour = hour - 1;
    }
    else {
        new_minute = minute - 45;
        new_hour = hour;
    }

    cout << new_hour << " " << new_minute;
}

/* Priyansh Agarwal*/
#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int steps = 0;
    while(n > 0){
        string a = to_string(n);
        char maximumDigit = '0';
        for(auto i : a){
            maximumDigit = max(maximumDigit, i);
        }
        steps++;
        n -= (maximumDigit - '0');
    }
    cout << steps << endl;
    return 0;
}
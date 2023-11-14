/* Priyansh Agarwal*/
#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> dp(n + 1, 1e9);
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        string a = to_string(i);
        for(char c : a){
            int digit = c - '0';
            if(digit != 0){
                dp[i] = min(dp[i], dp[i - digit] + 1);
            }
        }
    }
    cout << dp[n] << endl;
    return 0;
}
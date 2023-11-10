/* Priyansh Agarwal*/
#include<bits/stdc++.h>

#define MOD 1000000007
 
using namespace std;
void solve1(){   
    int n;
    cin >> n;
    vector<int> dp(n + 1);
    // state
    // dp[i] = number of ways to make a sum of i
    
    // base case
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 6; j++){
            if(j <= i){
                // transition
                dp[i] = (dp[i] + dp[i - j]) % MOD;
            }
        }
    }
    
    //final subproblem
    cout << dp[n] << endl;
}
 
void solve2(){
    int n;
    cin >> n;
    vector<int> dp(n + 1);
    // dp[i] = number of ways to make a sum of n 
    // such that the current sum is i
    
    // base case
    dp[n] = 1;
    for(int i = n - 1; i >= 0; i--){
        for(int j = 1; j <= 6; j++){
            if(j <= n - i){
                // transition
                dp[i] = (dp[i] + dp[i + j]) % MOD;
            }
        }
    }
    
    //final subproblem
    cout << dp[0] << endl;
}
 
 
int main() {
    // solve1();
    solve2();
}
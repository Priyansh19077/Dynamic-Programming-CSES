/* Priyansh Agarwal*/
#include<bits/stdc++.h>

#define MOD 1000000007

using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    vector<int> dp(x + 1, 0); 
    // initializing the dp values with a very high value initially
    // dp[i] = min coins to generate a sum of i
    
    // base case
    dp[0] = 1;
    
    // dp[x] -> dp[x - ci]
    
    for(int i = 1; i <= x; i++){ // O(x)
        // find dp[x]
        for(int j = 0; j < n; j++){ // O(n)
            if(a[j] <= i){
                // transition
                dp[i] = (dp[i] + dp[i - a[j]]) % MOD;
            }
        }
    }
    
    //final subproblem
    cout << dp[x] << endl;
    return 0;
}

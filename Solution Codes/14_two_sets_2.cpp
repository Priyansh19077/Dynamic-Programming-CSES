/* Priyansh Agarwal*/
#include<bits/stdc++.h>

#define MOD 1000000007
 
const long long mod_inverse_2 = 500000004;

using namespace std;

int main(){
    int n;
    cin >> n;
    if((n * (n + 1)) % 4 != 0){
        cout << 0 << endl;
        return 0;
    }
    int maxSum = (n * (n + 1)) / 4;
    
    vector<vector<long long>> dp(n + 1, vector<long long>(maxSum + 1, false));
    // dp[i][j] = number of ways to generate a sum of j with subsets
    // from first i numbers
    
    // base case, if there are no elements, only 0 can be generated
    // such that we don't pick any element    
    dp[0][0] = 1;
    
    for(int i = 1; i <= n; i++){
        int val = i;
        for(int j = 0; j <= maxSum; j++){
            // find dp[i][j] here
            dp[i][j] = dp[i - 1][j];
            if(j - val >= 0){
                dp[i][j] = (dp[i][j] + dp[i - 1][j - val]) % MOD;
            }
        }
    }
    cout << ((dp[n][maxSum] * mod_inverse_2) % MOD) << endl;
}

/* Priyansh Agarwal*/
 
#include<bits/stdc++.h>
 
using namespace std; 
int main(){
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    vector<int> dp(x + 1, 1e9); 
    // initializing the dp values with a very high value initially
    // dp[i] = min coins to generate a sum of i
    
    // base case
    dp[0] = 0;
    
    for(int i = 1; i <= x; i++){
        for(int j = 0; j < n; j++){
            if(a[j] <= i){
                // transition
                dp[i] = min(dp[i], dp[i - a[j]] + 1);
            }
        }
    }
    
    //final subproblem
    cout << (dp[x] < 1e9 ? dp[x] : -1) << endl;
    return 0;
}
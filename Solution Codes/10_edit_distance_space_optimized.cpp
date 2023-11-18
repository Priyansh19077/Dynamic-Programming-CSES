/* Priyansh Agarwal*/
#include<bits/stdc++.h>

#define MOD 1000000007
 
using namespace std;

int main(){
    string a, b;
    cin >> a >> b;
    int n = a.length(); // n <= 100
    int m = b.length(); // m <= 10^5
    // O(min(n, m)) 
    if(n < m){
        swap(a, b);
        swap(n, m);
    } 
    // base case
    vector<int> prev(m + 1); // currently stores dp[0][j]
    for(int j = 0; j <= m; j++){
        prev[j] = j;
    }
    
    for(int i = 1; i <= n; i++){
        vector<int> current(m + 1);
        current[0] = i; // means dp[i][0] = i
        for(int j = 1; j <= m; j++){
            char x = a[i - 1];
            char y = b[j - 1];
            
            // transition
            if(x == y){ // don't do anything
                current[j] = prev[j - 1];
            // current[j] = dp[i][j]
            // prev[j - 1] = dp[i - 1][j - 1]
            }else{ // replace character to match
                current[j] = prev[j - 1] + 1;
            }
            
            // skip ith character or add one character after jth character
            current[j] = min(current[j], prev[j] + 1);
            
            // skip jth character or add one character after ith character
            current[j] = min(current[j], current[j - 1] + 1);
        }
        prev = current;
    }
    
    // final subproblem
    cout << prev[m] << endl;
    return 0;
}

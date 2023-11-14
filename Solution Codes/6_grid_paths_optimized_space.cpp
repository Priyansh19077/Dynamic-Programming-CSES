/* Priyansh Agarwal*/
#include<bits/stdc++.h>

#define MOD 1000000007
 
using namespace std;

int main(){
    int n;
    cin >> n;
    string arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    // base case
    vector<int> nextRow(n);
    if(arr[n - 1][n - 1] == '.')
        nextRow[n - 1] = 1;
    else
        nextRow[n - 1] = 0;
    
    for(int i = n - 2; i >= 0; i--){
        if(arr[n - 1][i] == '.')
            nextRow[i] = nextRow[i + 1];
        else
            nextRow[i] = 0;
    }
    
    for (int i = n - 2; i >= 0; i--)
    {
        vector<int> currentRow(n);
        for (int j = n - 1; j >= 0; j--)
        {
            if (i == n - 1 && j == n - 1)
                continue;
            if (arr[i][j] == '*')
                currentRow[j] = 0;
            else
            {
                int ans1 = i < n - 1 ? nextRow[j] : 0;
                int ans2 = j < n - 1 ? currentRow[j + 1] : 0;
                // transition
                currentRow[j] = (ans1 + ans2) % MOD;
            }
        }
        nextRow = currentRow;
    }
    
    //final subproblem
    cout << nextRow[0] << endl;    
    return 0; 
}

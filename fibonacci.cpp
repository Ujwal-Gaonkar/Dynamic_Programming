/*---Ujwal Gaonkar---*/
#include <bits/stdc++.h>
using namespace std;

/*
Recursive Solution
    TC : O(2^n)
    SC : O(n) stack space
int fib(int n)
{
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

int main()
{
    int n;
    cin >> n;
    cout << fib(n) << endl;
}

*/

/*
Memoization Solution
    TC : O(n)
    SC : O(n) stack space + O(n) table
int fib(int n , vector<int> & dp)
{
    if(n<=1)
        return n;

    if(dp[n]!=-1)
        return dp[n];

    return dp[n]=fib(n-1,dp)+fib(n-2,dp);
}

int main()
{
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    cout<<fib(n,dp)<<endl;
}

*/

/*
Top-down approach
    TC : O(n)
    SC : O(n)
int fib(int n,vector<int>&dp)
{
    dp[0]=0;
    dp[1]=1;

    for(int i=2;i<=n;i++)
        dp[i]=dp[i-1]+dp[i-2];

    return dp[n];
}
int main()
{
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    cout<<fib(n,dp);
}

*/

/*
    Space Optimization
    TC : O(n)
    SC : O(1)
*/

int fib(int n)
{
    if(n<=1)    return n;
    int a=0,b=1,sum;
    for(int i=2;i<=n;i++)
    {
       sum = a + b;
       a = b;
       b = sum;
    }
    return sum;
}

int main()
{
    int n;
    cin>>n;
    cout<<fib(n)<<endl;
}


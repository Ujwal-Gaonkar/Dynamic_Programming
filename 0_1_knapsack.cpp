/*Recursive code
#include<bits/stdc++.h>
using namespace std;

int knapsack(int val[],int wt[],int w,int n)
{
    if(n==0||w==0)  return 0;

    if(wt[n-1]<=w)
        return max(val[n-1]+knapsack(val,wt,w-wt[n-1],n-1),knapsack(val,wt,w,n-1));
    else if(wt[n-1]>w)
        return knapsack(val,wt,w,n-1);
}

int main()
{
    int n;
    cin>>n;
    int wt[n];
    int val[n];
    for(int i=0;i<n;i++)
        cin>>val[i];
    for (int i = 0; i < n; i++)
        cin >> wt[i];
    int w;
    cin>>w;
    cout<<knapsack(val,wt,w,n);
}
*/
/* recursion + memoization(dp)
#include <bits/stdc++.h>
using namespace std;
int a[100][100];
int knapsack(int val[], int wt[], int w, int n)
{
    if (n == 0 || w == 0)
        return 0;
    if(a[n][w]!=-1)
        return a[n][w];
    if (wt[n - 1] <= w)
        return a[n][w]=max(val[n - 1] + knapsack(val, wt, w - wt[n - 1], n - 1), knapsack(val, wt, w, n - 1));
    else if (wt[n - 1] > w)
        return a[n][w]=knapsack(val, wt, w, n - 1);
}

int main()
{
    memset(a, -1, sizeof(a));
    int n;
    cin >> n;
    int wt[n];
    int val[n];
    for (int i = 0; i < n; i++)
        cin >> val[i];
    for (int i = 0; i < n; i++)
        cin >> wt[i];
    int w;
    cin >> w;
    cout << knapsack(val, wt, w, n);
}

*/

// top-down(real DP)
#include <bits/stdc++.h>
using namespace std;
int dp[100][100];
int knapsack(int val[], int wt[], int w, int n)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            if (wt[i - 1] <= j)
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][w];
}

int main()
{
    int n;
    cin >> n;
    int wt[n];
    int val[n];
    for (int i = 0; i < n; i++)
        cin >> val[i];
    for (int i = 0; i < n; i++)
        cin >> wt[i];
    int w;
    cin >> w;
    cout << knapsack(val, wt, w, n);
}
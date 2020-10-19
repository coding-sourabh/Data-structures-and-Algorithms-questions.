/*
problem :
Given two numbers X and N, find out the total number of ways X can be expressed as sum of Nth power of unique natural numbers.

Examples:

Input  : X = 10, N = 2
Output : 1
Explanation: 10 = 12 + 32, 
Hence total 1 possibility

Input  : X = 100, N = 2
Output : 3
Explanation: 100 = 102
             OR 62 + 82
             OR 12 + 32 + 42 + 52 + 72
Hence total 3 possibilities
*/

***************************************************************************************************************************************************************************

#include<bits/stdc++.h>
using namespace std;
#define vi               vector<int>
#define pii              pair<int,int>
#define si               set<int>
#define ff               first
#define ss               second
#define mii              map<int,int>
#define umii             unordered_map<int,int>
#define p_b              push_back
#define pqi               priority_queue<int>
#define loop(i,a,b)      for(int i=a;i<b;i++)
#define int              long long
#define io          	 ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define multipletest     int t;cin>>t;while(t--) 
bool isPrime(int n){if(n==1){return false;}if(n==2){return true;}if(n%2==0){return false;}for(int i = 3; i <= sqrt(n); i+=2){if(n % i == 0){return false;}}return true;}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////f//////////////////////////////////////////////////////////////////////////////

int findWays(int x , int n , int start)
{
    if(x == 0)
      return 1;
    if(x < 0)
      return 0;
      
    int ans = 0;
    
    for(int i=start ; pow(i , n) <= x ; i++)
    {
         ans += findWays(x - pow(i , n) , n , i+1);
    }
    
    return ans;
}

void solve()
{
    int x , n;
    cin>>x>>n;
    
    cout<<findWays(x , n , 1)<<endl;
}

int32_t main()
{
	io
 	multipletest
	solve();
}

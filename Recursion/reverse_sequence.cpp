A function f is defined as follows F(n)= (1) +(2*3) + (4*5*6) ... n. Given an integer n the task is to print the F(n)th term.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test contains an integer n.

Output:
For each test case print the nth term of the sequence.

Example:
Input:
2
5
7
Output:
365527
6006997207

******************************************************************************************************************************************************************************

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

int findVal(int n , int limit , int start)
{
    
    int ans=1;
    
    if(limit > n) return 0;
    
         for(int i=1 ; i <= limit ; i++)
            ans *=  (start++);
    
    return ans + findVal(n , limit+1 , start);
}

void solve()
{
    int n;
    cin>>n;
    
    cout<<findVal(n , 1 , 1)<<endl;
}

int32_t main()
{
	io
 	multipletest
	solve();
}

Given a number N, let the reverse of the number be R. The task is to print the output of the Expression pow(N,R), where pow function represents N raised to power R.
Note: As answers can be very large, print the result modulo 1000000007.

Input:
The first line of the input consists of an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of a single line containing an integer N.

Output:
Corresponding to each test case, print in a new line, the output of the expression pow as described above.

Example:
Input:
2
2
12

Output:
4
864354781

**********************************************************************************************************************************************************************************

#include<bits/stdc++.h> 
using namespace std;
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

const int mod = 1000000007;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////f//////////////////////////////////////////////////////////////////////////////

int power(int n , int r)
{
//   if(r == 1) return (n+mod)%mod;  why wrong?
   
   if(r == 0) return 1;
   
   int x = power(n , r/2)  % mod;
   
   x = (x*x) % mod;
   
   if(r&1)
     x = (x*n)%mod;

   return (x+mod)%mod;
}

int getReverse(int n)
{
    int ans = 0;
    
    while(n)
    {
        ans = ans*10 + n%10;
        n /= 10;
    }
    
    return ans;
}

void solve()
{
    int n;
    cin>>n;
    
   int r = getReverse(n);
   
  cout<<power(n,r)<<endl;
}

int32_t main()
{
	io
 	multipletest
	solve();
}

Mila and Gila are sisters, Mila being the younger one. Mila and Gila both have some number of coins of different denominations with them. 
Mila being a stubborn little sister won’t share her coins with anyone but wants that both of the sisters have equal money. 
Gila being an understanding elder sister accepts to give some of her coins to Mila if that can make the money equal.

As Mila won’t share any of her coins with anyone, you are only provided with the total money with Mila and no details of her denominations.

You are required to find out whether they can distribute the money among themselves such that both of them have equal money. 

Input:

The first line of the input consists of a single integer T denoting the number of test cases. Each of the test cases consists of two lines.
The first line of each test case contains space separated two integers N and M, denoting the number of coins with Gila and the total amount present with 
Mila respectively. 
The next line contains space separated N integers denoting the value of each coin with Gila.

Output:

Print ‘1’ if they can distribute the money among themselves such that both of them have equal amount. Else, print ‘0’.
For each test case, print the output in a new line. 

Example:
Input:
2
5 6
1 2 3 0 6
5 5
1 2 3 2 6

Output:
1
0

Explanation:
For the 1st test case:
Gila can give her Rs. 3 coin to Mila. Hence, both of them would have Rs. 9
For the 2nd test case:
There is no combination of coins Gila can give to her sister such that both of them would have the same amount.

*********************************************************************************************************************************************************************************4

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

bool isPossible(int *a , int n , int req)
{
    if(req == 0) return true;
    if(n == 0 || req < 0)  return false;
    
    return (isPossible(a , n-1 , req - a[n-1])) || (isPossible(a , n-1 , req));
}

void solve()
{
    int n , milaMoney;
    cin>>n>>milaMoney;
    
    int deno[n];
    int sum =0 ;
    
    for(int i=0 ; i < n; i++){
      cin>>deno[i];
      sum += deno[i];
    }
    
    if( ((sum + milaMoney) & 1) || (milaMoney > sum))
      {
          cout<<0<<endl;
          return;
      }
      
      if(milaMoney == sum)
      {
          cout<<1<<endl;
          return;
      }
      
      cout<<isPossible(deno , n , (sum - milaMoney) / 2)<<endl;
    
}

int32_t main()
{
	io
 	multipletest
	solve();
}

Some people are standing in a queue. A selection process follows a rule where people standing on even positions are selected. Of the selected people a queue is formed and again out of these only people on even position are selected. This continues until we are left with one person. Find out the position of that person in the original queue.

Input:
The first line of input contains an integer T denoting the number of test cases.The first line of each test case is N,number of people standing in a queue.

Output:
Print the position(original queue) of that person who is left.

Example:
Input:
2
5
9
Output:
4
8

*******************************************************************************************************************************************************************************

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

int leftPerson(vi v)
{
    if(v.size() == 1) 
       return v[0];
    
    vi newV;
    
    for(int i=0 ; i < v.size() ; i++)
    {
        if(i % 2 == 1)
           newV.push_back(v[i]);
    }
    
    return leftPerson(newV);
}

void solve()
{
    int n;
    cin>>n;
    vi v(n);
    
    for(int i=0 ; i < n ; i++) 
        v[i] = i+1;
    
    // cout<<leftPerson(v)<<endl;
    
    // Direct Formula
       int x = log(n) / log(2);
       int ans = (1<<x);
       cout<<ans<<endl;
}

int32_t main()
{
	io
 	multipletest
	solve();
}

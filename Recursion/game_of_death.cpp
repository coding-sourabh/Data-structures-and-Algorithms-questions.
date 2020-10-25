There are n people standing in a circle (numbered clockwise 1 to n) waiting to be executed. The counting begins at point 1 in the circle and proceeds around the circle in a fixed direction (clockwise). In each step, a certain number of people are skipped and the next person is executed. The elimination proceeds around the circle (which is becoming smaller and smaller as the executed people are removed), until only the last person remains, who is given freedom.
Given the total number of persons n and a number k which indicates that k-1 persons are skipped and kth person is killed in circle. The task is to choose the place in the initial circle so that you are the last one remaining and so survive.
Consider if n = 5 and k = 2, then the safe position is 3.
Firstly, the person at position 2 is killed, then person at position 4 is killed, then person at position 1 is killed. Finally, the person at position 5 is killed. So the person at position 3 survives.

Input:
The first line of input contains a single integer T denoting the number of test cases. Then T test cases follow. The first and only line of each test case consists of two space separated positive integers denoting n and k.

Output:
Corresponding to each test case, in a new line, print the safe position.

Example:
Input:
3
2 1
4 2
50 10
Output:
2
1
36

Explanation:
Testcase 1: here n = 2 and k = 1, then safe position is 2 as the person at 1st position will be killed.

*********************************************************************************************************************************************************************************

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

int find(vi jos , int n , int k , int ind)
{
    if(jos.size() == 1) return jos[0];
    
    int cur = (ind + k)%jos.size();
    
    jos.erase(jos.begin() + cur);
    
    return find(jos , jos.size() , k , cur);
}
void solve()
{
    int n,k;
    cin>>n>>k;
    
    vi jos;
    
    for(int i=0 ; i < n ; i++)
      jos.p_b(i);
    
    cout<<find(jos , n , k-1 , 0)+1<<endl;
}

int32_t main()
{
	io
 	multipletest
	solve();
}

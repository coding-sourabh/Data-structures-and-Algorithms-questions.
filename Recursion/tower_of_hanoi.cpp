The tower of Hanoi is a famous puzzle where we have three rods and N disks. 
The objective of the puzzle is to move the entire stack to another rod. You are given the number of discs N. Initially, these discs are in the rod 1.
You need to print all the steps of discs movement so that all the discs reach the 3rd rod. Also, you need to find the total moves.
Note: The discs are arranged such that the top disc is numbered 1 and the bottom-most disc is numbered N. 
Also, all the discs have different sizes and a bigger disc cannot be put on the top of a smaller disc.

Input:
The first line of input is T denoting the number of testcases. T testcases follow. Each testcase contains a single line of input containing N.

Output:
For each testcase, print the steps and the total steps taken. Please see the example output to see the steps format.

Example:
Input:
2
2
3
Output:
move disk 1 from rod 1 to rod 2
move disk 2 from rod 1 to rod 3
move disk 1 from rod 2 to rod 3
3
move disk 1 from rod 1 to rod 3
move disk 2 from rod 1 to rod 2
move disk 1 from rod 3 to rod 2
move disk 3 from rod 1 to rod 3
move disk 1 from rod 2 to rod 1
move disk 2 from rod 2 to rod 3
move disk 1 from rod 1 to rod 3
7

****************************************************************************************************************************************************************************

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

int steps(int n , int src , int aux , int dest )
{
    if(n == 1)
    {
        cout<<"move disk "<<n<<" from rod "<<src<<" to rod "<<dest<<endl;
        return 1;
    }
    
    int x = steps(n-1 , src , dest , aux);
    
    cout<<"move disk "<<n<<" from rod "<<src<<" to rod "<<dest<<endl;
    
    x += steps(n-1 , aux , src , dest);
    
    return x+1;
}

void solve()
{
     int n;
     cin>>n;
     
     int src = 1 , aux = 2 , dest = 3;
     
     cout<<steps(n , src , aux,  dest)<<endl;
}

int32_t main()
{
	io
 	multipletest
	solve();
}

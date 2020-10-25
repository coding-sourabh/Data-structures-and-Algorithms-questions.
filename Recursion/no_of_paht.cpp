The problem is to count all the possible paths from top left to bottom right of a MxN matrix with the constraints that from each cell you can either move to right or down.

Example 1:

Input:
M = 3 and N = 3
Output: 6
Explanation:
Let the given input 3*3 matrix is filled 
as such:
A B C
D E F
G H I
The possible paths which exists to reach 
'I' from 'A' following above conditions 
are as follows:ABCFI, ABEHI, ADGHI, ADEFI, 
ADEHI, ABEFI

*****************************************************************************************************************************************************************************

#include<bits/stdc++.h>
using namespace std;

long long paths(int n , int m , int i , int j)
{
    if(i < 0 || j < 0 || i >= n || j >= m) return 0;
    
    if(i == n-1 && j == m-1)
      return 1;
    
    return paths(n , m  , i+1 , j ) + paths(n ,  m , i , j+1);
}

long long  numberOfPaths(int n, intm)
{
    return paths(n , m , 0 , 0);
}

int main()
{
   int n,m;
   cin>>n>>m;
   
   cout<<numberOfPaths(n , m )<<endl;
}

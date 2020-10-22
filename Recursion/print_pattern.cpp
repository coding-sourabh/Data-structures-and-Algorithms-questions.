Print a sequence of numbers starting with N, without using loop, in which  A[i+1] = A[i] - 5,  if  A[i]>0, else A[i+1]=A[i] + 5  repeat it until A[i]=N.

Input:
The first line contains an integer T, number of test cases. Then following T lines contains an integer N.

Output:
For each test case, print the pattern in newline with space separated integers.

Example:
Input:
2
16
10
Output:
16 11 6 1 -4 1 6 11 16
10 5 0 5 10

****************************************************************************************************************************************************************************

#include <iostream>
using namespace std;

int solve(int x )
{
    if(x <= 0){
        cout<<x<<" ";
        return x;
    }
    
    cout<<x<<" ";
    int y = solve(x - 5) + 5;
    cout<<y<<" ";
    
    return y;
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    
	    solve(n);
	    cout<<endl;
	}
	return 0;
}

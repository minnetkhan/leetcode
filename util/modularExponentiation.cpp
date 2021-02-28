// Date   : 28-02-2021

/********************************************************************************** 

Given three numbers x, y and p, compute (xy) % p. 

Input:  x = 2, y = 5, p = 13
Output: 6
Explanation: 2^5 % 13 = 32 % 13 = 6.

**********************************************************************************/

#include <iostream>
using namespace std;


int power(long long x, unsigned int y, int p) 
{ 
    int res = 1;
 
    x = x % p; 
  
    if (x == 0) return 0;
 
    while (y > 0) 
    { 
        
        if (y & 1) 
            res = (res*x) % p; 
 
        y = y>>1;
        x = (x*x) % p; 
    } 
    return res; 
} 

int main() {
	int x=2;
	int y=5;
	int p=13;
	
	cout<<power(x, y, p)<<endl;

	return 0;
}
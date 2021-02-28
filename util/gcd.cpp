// Date   : 28-02-2021

/********************************************************************************** 

GCD (Greatest Common Divisor) or HCF (Highest Common Factor) of two numbers is the 
largest number that divides both of them. 

For example GCD of 20 and 28 is 4
GCD of 98 and 56 is 14.

**********************************************************************************/

#include <iostream>
using namespace std;


// gcd(36, 20) => 4
int gcd(int a, int b) {
	if(b == 0)
		return a;

	return gcd(b, a%b);
}

int main() {
	int a, b;
	a = 20;
	b = 28;
	
	cout<<gcd(a, b)<<endl;

	return 0;
}
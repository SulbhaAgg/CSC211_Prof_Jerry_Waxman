#include <iostream>
/*
*   Title: Integration
*	Description : The goal of this project is to find the area of a function between two points. 
				  The program uses typedef to create an alias for a function. By doing so, we can
				  pass a function as a parameter for another function call. 
	Author: Prof Waxman gave the code for functions except integration function
	        Sulbha Aggarwal - Wrote the code for integrate function, integrate function
			                  makes call to different functions and calculate integration by incrementing the value of x by delta.
*/

using namespace std ;
typedef double (*FUNC)(double) ;
double integrate( FUNC f , double a , double b ) 
{
	double x = a ;
	double delta = .0001 ;
	double total = 0 ;
	
	while( x < b )
	{
		total += f(x)*delta ;
		x += delta ;
	}
	return total ;
}
double line( double x )
{
	return x ;
}

double square( double x )
{
	return x*x ;
}

double cube( double x )
{
	return x*x*x ;
}

int main()
{
	cout << "The integral of f(x)=x between 1 and 5 is: " << integrate( line, 1, 5 ) << endl ;
	cout << "The integral of f(x)=x^2 between 1 and 5 is: " << integrate(square, 1, 5 ) << endl ;
	cout << "The integral of f(x)= x^3 between 1 and 5 is: " << integrate(cube, 1, 5 ) << endl ; 
}

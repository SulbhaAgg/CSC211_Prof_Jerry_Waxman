#include <iostream>
#include <cmath>
/*
* Title: 		n Queens
* Description : The goal of this project is to find the 
				solutions to the n number of queens on a nxn board. 
				This project uses dynamic arrays and dynamic memory to accomplish its task. 
  Author: 		Sulbha Aggarwal
*/
using namespace std;

// Returns true if the queen in column c is ok
bool ok(int q[], int c) 
{
   for( int i = 0 ;i < c ; i++ )
		if( q[i] == q[c] || ( (c-i) == abs( q[c]-q[i] ) ) )
			return false ;
	return true ;
}


int main() 
{
    int n ;
    int num = 0 ;
    cout << "n =  " ;
    cin >> n ;
    for( int i = 1 ; i <= n ; i++ )
    {
        int *q = new int[i] , c = 0 ;                                 // Initialize the array to 0.
        q[c] = 0 ;                                               // Start in the 1st row, 1st column
        c++ ;
        while (c >= 0) 
        { 
            if( c > i-1 )                                           // If you have passed the last column,
       	    {           
               num++ ; 
               c-- ;
        	}
            else
          		q[c] = -1 ; // Otherwise, move to one before the first row
          		
            while ( c >= 0 && c < i ) 
        	{
                q[c]++ ;      // Move to the next row
                if( q[c] == i ) // If you have passed the end of the column, backtrack
          			c-- ;
                else
                  if( ok( q , c ) == true ) // Otherwise, call the ok function.  If it returns true, go back to the beginning of the outer loop.
              	  {
        			c++ ;
        			break ;
              	  }
            }
        }
    	cout << "\nThere are " << num << " solutions to the " << i << " queens problem." ;
    	
    	num = 0 ;
    	delete q;
    }
   return 0;
}


#include <iostream>

/**
Title - Equivalent Arrays
Description - Check whether two arrays are shift equivaent if yes return true, otherwise return false.
Author - Sulbha Aggarwal
*/

using namespace std;

bool equivalent(int a[], int b[], int n)
{
	/*found is to see if first elemnet in array A matches the any element in Array B 
	* if yes than found becomes true other wise false is return to exit the program
	*/
    bool found = false ;            
    for( int i = 0 ; !found && i < n ; i++ )
        if( a[0] == b[i] )
            found = true ;
            
    if( found == false )
        return false ;
        
    int pos = 0 ;            // for the position of index of array B
    int pos1 = 0 ;           // for incrementing the array index by 1 to make sure every single possibility is checked for array equvilency
    int i = 0 ;
    while( i < n )
    {
        if( a[i] == b[pos%n] )
        {
            pos++ ;
            i++ ;
        }
        //if only the last element of the array A does not match array B than exit the program 
		//else if( i == (n-1) )
        //     return false ;
        else 
        {
            i = 0 ;
            pos1++ ;
            //if the index of the array has been incremented more than size of the array than exit the function
            if( pos1 >= n )
            	return false ;
            pos = pos1 ;
        }
    } // end of while loop
    return true ;              // This will return true only when Array A is shift equivalent to Array B
}

int main() {
   cout << boolalpha; // to print bool values as true/false instead of 1/0
   
   int a1[5] = {1, 2, 3, 4, 5};
   int a2[5] = {3, 4, 5, 1, 2};
   cout << equivalent(a1, a2, 5) << endl; // true
   
   int b1[3] = {1, 2, 3};
   int b2[3] = {2, 3, 3};
   cout << equivalent(b1, b2, 3) << endl; // false
   
   int c1[4] = {2, 3, 4, 1};
   int c2[4] = {1, 4, 3, 2};
   cout << equivalent(c1, c2, 4) << endl; // false
   
   int d1[4] = {3, 2, 3, 1};
   int d2[4] = {3, 1, 3, 2};
   cout << equivalent(d1, d2, 4) << endl; // true
   
   int e1[5] = {1, 1, 1, 1, 2};
   int e2[5] = {1, 1, 1, 2, 1};
   cout << equivalent(e1, e2, 5) << endl; // true
   
   return 0;
}

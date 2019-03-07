/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/**
 * Author- Sulbha Aggarwal
 * Title- Perfect sqaure
 * Description- Program to print perfect square whose last two digits are both odd
 * */

#include <iostream>

using namespace std;

int main()
{
    bool found = false ;
    for( int i = 1 ; i < 100 ; i++ )
        {
            
            //This is the if statement to check if i is odd because even numbers have even squares
            if( i % 2 != 0 )
                {
                    int square = i*i ;
            
                    //This is a debugger to see if my program actually goes upto 99
                    //cout << "i is: " << i << " Square is: " << square << endl ;
            
            
                    if( ( square%2 != 0 )  &&  ( (square/10)%2 != 0 ) )
                        {
                            cout << "The number is " << i << "\nThe perfect square is : " ;
                            found = true ;
                            i = 100 ;
                        }// end of if statement
                }// end of if statement
        }// end of for loop
    if( found != true )
    	cout << "Result is : No solution" ;
    
   
}

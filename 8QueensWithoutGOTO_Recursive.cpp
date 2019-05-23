#include <iostream>
#include <cmath>
/*
*   Title: 8 Queens 1D without GOTO using resursion
*	Description : The purpose of this program is to solve the 8 Queens problem; place 8 Queens on a 
                  8 x 8 Chessboard such that no two queens threathen each other. No two queens may be 
				  in the same row, column, or diagonal. This problem has 92 different configurations 
				  or solutions. This will be solved by recursion which does the work of backtracking 
				  algorithem as well. When one place is out of numbers, it goes back to privous call
				  and find another number for previous place.                   
	Author: I used the guideline gave by Alex Chan on his website.
	        Sulbha Aggarwal- Wrote the code for 8Queens 1D without GOTO
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

void print(int q[]) 
{
   static int numSolutions = 0;
   cout << "Solution #" << ++numSolutions << ":\n" ;
   // Print the array
   for( int i = 0 ; i < 8 ; i++ )                        //for going through whole 1D array
			{
				/*for going through the entire array and looking at which index is queens that i am looking for
				  example: i is 0, it means i am looking for queens at row 0 so j go thorugh all the columns to find a queens at row 0
				*/
				for( int j = 0 ; j < 8 ; j++ )               
				{
					if( q[j] != i )
						cout << 0 << " " ;
					else
						cout << 1 << " " ;
				}
				cout << endl ;	
			}
		cout << endl ;
}

void next(int q[], int c) 
{
   if (c == 8)
      print(q);
   else 
   	for ( q[c] = 0 ; q[c] < 8 ; q[c]++ )
      if ( ok(q, c) )
         next( q, c+1 ) ;
}

int main() 
{
   int q[8];
   next(q, 0);
   return 0;
}

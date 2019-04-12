#include <iostream>
#include <cmath> 

/*
*   Title: 8 Queens 1D
*	Description : The purpose of this program is to solve the 8 Queens problem; place 8 Queens on a 
                  8 x 8 Chessboard such that no two queens threathen each other. No two queens may be 
				  in the same row, column, or diagonal. This problem has 92 different configurations 
				  or solutions. This will be solved by implementing a backtracking algorithm.
	Author: Prof Waxman gave the whole code for placing the queens in 8 unique spot on chessboard
	        Sulbha Aggarwal - Just the print part, every time there are unique 8 spots program will print solution
*/

using namespace std;

int main()
{
	
	int q[8] , c = 0 ;  // declared 1D array q and c for keeping taking of currently working index
	q[0] = 0 ;          // First spot in array intialized to 0 which meach queen is placed at row and column 0 on chess board
	
	Nc:
		c++ ;           
		if( c == 8 )
			goto print ;
		
		q[c] = -1 ;
		
	Nr:
		q[c]++ ;
		if( q[c] == 8 )
			goto Backtrack ;
			
	//row test and diagonal test
	for( int i = 0 ; i < c ; i ++ )
		if( (q[i] ==  q[c]) || ( (c-i) == abs(q[c]-q[i]) ) )
			goto Nr ;
			
	goto Nc ;
	
	Backtrack:
		c-- ;
	
	if( c == -1 )
		return 0 ;
		
	goto Nr ;
	
	print:
		static int numSolutions = 0;
        cout << "Solution #" << ++numSolutions << ":\n" ;
        
        // I used nested for loops to print 1D to 2D array
		for( int i = 0 ; i < c ; i++ )                        //for going through whole 1D array
			{
				/*for going through the entire array and looking at which index is queens that i am looking for
				  example: i is 0, it means i am looking for queens at row 0 so j go thorugh all the columns to find a queens at row 0
				*/
				for( int j = 0 ; j < c ; j++ )               
				{
					if( q[j] != i )
						cout << 0 << " " ;
					else
						cout << 1 << " " ;
				}
				cout << endl ;	
			}
		cout << endl ;
		
		goto Backtrack ;
}

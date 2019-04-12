#include<iostream>
using namespace std;

/*
* Title:          Stable Marriage
* Description :   The goal of this project to match n men and n women with their preference rankings 
                  of each other and give a "stable" set of marriages. This project uses backtracking to find its solutions.
* Author:         Guideline from Alex Chen's website.
*                 Sulbha Aggarwal- Wrote the code for Stable Marriage.
*/

bool ok( int q[], int c ) 
{ // Finish this code
	static int mp[3][3] = { { 0,2,1 },  	 // Man#0's preferences
							{ 0,2,1 },		// Man#1's preferences
							{ 1,2,0 } } ;	// Man#2's preferences
						
	static int wp[3][3] = { { 2,1,0 },		// Woman#0's preferences
							{ 0,1,2 },		// Woman#1's preferences
							{ 2,0,1 } } ;	 // Woman#2's preferences

	for( int i = 0 ; i < c ; i++ )
	{
		if( q[i] == q[c] )                             //if the same women is married to two different man return false
			return false ;
			
	    //if (women#c) and (woman#i's husband) both like each other more than their own spouse
		if( ( wp[q[c]][c] > wp[q[c]][i] ) && ( mp[i][q[i]]  > mp[i][q[c]] ) )               
			return false ;
		
		//if (Man#c) and (Man#i's wife) both like each other more than their own spouse
		if( ( mp[c][q[c]] > mp[c][q[i]] ) && ( wp[q[i]][i] > wp[q[i]][c] ) )
			return false ;
	}

	//return true if marriage is stable
	return true ;
}

void print(int q[] , int c ) 
{
	static int solution = 0;
	cout << "Solution #" << ++solution << ":\nMan\tWoman\n";
	//Finish this print function
	for( int i = 0 ; i < c ; i++ )
		cout << i << "\t" << q[i] << endl ;
	cout << endl;
}


int main() 
{
	//The main function is exactly the same as 1D Queens.
   int q[3] = {0} , c = 0 ;                                 // Initialize the array to 0.
   q[c] = 0 ;                                               // Start in the 1st row, 1st column
   c++ ;
   while (c >= 0) 
   { 
      if( c > 2 )                                           // If you have passed the last column,
	  {           
      	 print( q , c ) ; 										// Call the print function and backtrack
      	 c-- ;
	  }
      else
	  	  q[c] = -1 ; 										// Otherwise, move to one before the first row
      while ( c >= 0 && c < 3 ) 
	  {
         q[c]++ ;     										// Move to the next row
         if( q[c] == 3 )									// If you have passed the end of the column, backtrack
         		 c-- ;
         else
         {
         	if( ok( q , c ) == true ) 						// Otherwise, call the ok function.  If it returns true, go back to the beginning of the outer loop.
         		{
				 c++ ;
				 break ;
         		}		
         }
      }
   }
   return 0;
}

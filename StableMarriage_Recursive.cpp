#include<iostream>
using namespace std;

/*
* Title:          Stable Marriage
* Description :   The goal of this project to match n men and n women with their preference rankings 
                  of each other and give a "stable" set of marriages. This program uses recursion which 
                  does the work of backtracking algorithem as well. When one place is out of numbers, it 
				  goes back to privous call and find another number for previous place.    
* Author:         Sulbha Aggarwal
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

void next(int q[], int c) 
{
   if (c == 3)
      print( q , c ) ;
   else 
   	for (q[c] = 0; q[c] < 3; ++q[c])
      if (ok(q, c))
         next(q, c+1);
}

int main() {
   int q[3];
   next(q, 0);
   return 0;
}



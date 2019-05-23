#include <iostream>
#include <cmath>
/*
* Title: 		K Bishops
* Description : The goal of this project is to find the 
				solutions to the k number of Bishops on a nxn board. 
				This project uses dynamic arrays and dynamic memory to accomplish its task. 
  Author: 		Sulbha Aggarwal
*/

using namespace std;

//only does diagonal test
bool ok(int q[], int c, int n ) 
{
	int row = 0 , col = 0 ;
	int row1 = q[c]/n ;            //row of the current Bishop located at index c
	int col1 = q[c]%n ;            //col of the current Bishop located at index c
   for( int i = 0 ;i < c ; i++ )
   {
   	row = q[i]/n;                   //row of the current Bishop located at index i
   	col = q[i]%n ;                  //row of the current Bishop located at index i
   	if( abs(row1-row) == abs(col1-col) )
			return false ;
   }
	return true ;
}

int main()
{
	int n = 0 , k = 0 ;
	cout << "Enter a value of n: " ;
	cin >> n ;                                //Asking user to enter the size of the board
	int num = 0 ;                             //variable used to count how many ways k bishops can move around 
	
	while( n != -1 )                          //Keep going until user enters -1 for the size of the board
	{
		cout << "Enter a value of k: " ;      //Asking user to enter number of Bishops
		cin >> k ;
		int *q = new int [k] , c = 0 ;        //Careful- this time the size of array is k, which is number of Bishops
		q[c] = 0 ;                            //Starting by allocated bishop 1 slot number 0 
		c++ ;
		while( c >= 0 )                       //Until c is not -1, means no more solutions
		{
			if( c >= k )                      //if c is >= k, which means array q is full then add then increase number of solutions by another number
			{
				num++ ;
				c-- ;                         //Go back to previous column to get a different solution
			}
			else
				q[c] = q[c-1] ;               //else start from the index where the previous bishop left over and we already took care 
			                                  //of when c is 0 because we are starting from bishop number 1. When it goes to 0 to get another solution
			                                  //and every other solution it finds it goes directly to if consdition doesn't get to else.
			while( c >= 0 && c < k )
			{
				q[c]++ ;                      //go to next index in 2D array
				if( q[c] == (n*n) )           //if a bishop get out of bounds of array then backtrack
					c-- ;
				else
					if( ok( q , c , n ) )     //If we found a spot for bishop then go to next bishop and break the while loop
					{
						c++ ;
						break ;
					}
			}
			
			
		}
		cout << "Number of solutions: " << num ;    //print the number of solutions for that particular n*n board and k bishops
		num = 0 ;                                   //overwrite num to 0 
		delete q ;                                  //delete the current array q from the memory
		cout << "\n\nEnter value of n: " ;          //Enter a new value for n*n board
		cin >> n ;
	}  
}

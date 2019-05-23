#include<iostream>
#include<cmath>
using namespace std;
/*
* Title:          Eight Numbers in a Cross Recursive
* Description :   The purpose of this program is to write 8 numbers in a cross such that no two adjacent squares contains 
                  consecutive numbers. There are 4 solutions to this problem. This program uses recursion which 
                  does the work of backtracking algorithem as well. When one place is out of numbers, it goes back to 
				  privous call and find another number for previous place.                   
* Author:         Guideline from Alex Chen's website.
*                 Sulbha Aggarwal- Wrote the code for Eight Numbers in Cross.
*/

bool test(int cross[], int x) 
{
	static int checkList[8][5] = 
	{
		{-1},
		{0,-1},
		{1,-1},
		{0,1,2,-1},
		{1,2,3,-1},
		{2,4,-1},
		{0,3,4,-1},
		{3,4,5,6,-1},
	};
	//fill in 
	for( int i = 0 ; i < x ; i++ )                                   //test to place a unique number in cross at index x
		if( cross[x] == cross[i] )
			return false ;
	for( int i = 0 ; checkList[x][i] != -1 ; i++ )                    //test to check if the number at index x is not consective of its adjacent indexes
		if( abs( cross[x] - cross[checkList[x][i]]) == 1  )
			return false ;
	return true ;
} 

void print( int cross[] ) 
{
	static int count = 0;
	cout << "Soultion number: " << ++count << endl;
	cout << " " << cross[1] << cross[2] << endl;
	cout << cross[0] << cross[3] << cross[4] << cross[5] << endl;
	cout << " " << cross[6] << cross[7] << endl;
	return;
}

void next(int q[], int c) 
{
   if (c > 7)
      print(q);
   else 
   	for ( q[c] = 1 ; q[c] <= 8 ; q[c]++ )
      if ( test(q, c) )
         next(q, c+1);
}

int main() 
{
   int q[8];
   next(q, 0);
   return 0;
}


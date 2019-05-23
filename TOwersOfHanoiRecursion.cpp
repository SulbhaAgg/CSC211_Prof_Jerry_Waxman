#include <iostream>
#include <vector>
/*
*   Title: Towers of Honoi Recursive
*	Description : The goal is to move all of the disk from one tower to another tower, with the following rules:
				  Move one disk at a time
				  Only move from the top of the tower to the top of another tower
				  Never place a larger disk on a smaller disk
				  This project is done recursively so takes more time during run time.
	Author: Took help of classmaste Derek, becuase my code used vectors and was not even compiling and was not able to do cout 
	        "error: no match for ‘operator<<’ "- compiler was giving me this error. So Derek told me to try to make code without 
			vectors. I understood the code first on the paper before I ran it on computer. 	        
	        Sulbha Aggarwal - Wrote the whole code for moving the disks from tower A to B in ascending order
			                  top most tower being the smallest and bottom most being the largest			                  
*/
using namespace std;

void hanoi( char from , char to, char extra, int n )
{
	static int move = 0;             //for counting moves
	if( n == 1 )                     
	{
		cout << "move #" << ++move << " : transfer ring " << n << " from tower " << from << " to tower " << to << endl ;
		return ;
	}
	hanoi( from, extra, to, n-1 ) ;
	cout << "move #" << ++move << " : transfer ring " << n << " from tower " << from << " to tower " << to << endl ;
	hanoi( extra, to, from, n-1 ) ;
	return ;
}

int main()
{
	char A = 'a' , B = 'b' , C = 'c' ;
	int n ;
	cout << "Please enter number of rings to move: " ;
	cin >> n ;
	cout << endl ;
	hanoi ( A , B , C , n ) ;
	
}

#include <iostream>
#include <vector>
/*
*   Title: Towers of Honoi non-recursive
*	Description : The goal is to move all of the disk from one tower to another tower, with the following rules:
				  Move one disk at a time
				  Only move from the top of the tower to the top of another tower
				  Never place a larger disk on a smaller disk
				  This project will be using vectors.
	Author: Used the guideline provided by prof waxman for odd towers
	        Sulbha Aggarwal - Wrote the whole code for moving the disks from tower A to B in ascending order
			                  top most tower being the smallest and bottom most being the largest
			                  
	Note: Professor The code that you gave us in class and that prof Waxman provide in his notes, initializes all the towers 
		  by pushing n+1 on each vector but I did not do that. I tried to make my code with n ,i.e without initilaizing tower 1 and 2
		  , which was more work and i had to check for empty vectors in order to do that. My code is a little longer because of that
		  but i wrote a lot comments so that it is easier for you to read and understand the code.
*/

using namespace std;

int main() 
{
   vector<int> t[3];
   int n;
   cout << "Please enter the number of rings to move: ";
   cin >> n;
   cout << endl;
   
  
   int from = 0, to, candidate = 1, move = 0;
   
   if( n%2 == 0 )                               // The initial value of to depends on whether n is odd or even
   	to = 2;
   else 
   	to = 1 ;

   // Initialize the tower A
   for(int i = n ; i > 0; --i)
      t[0].push_back(i);
   
   while ( t[1].size() != n )                              // while t[1] does not contain all of the rings
   { 
      cout << "Move #" << ++move << ": Transfer ring " << candidate << " from tower " << char(from+'A') << " to tower " << char(to+'A') << "\n";
      
      // Move the ring from the "from tower" to the "to tower" (first copy it, then delete it from the "from tower")
      t[to].push_back( t[from].back() ) ;
      t[from].pop_back() ;
      
      if( t[1].size() != n )                      //to make sure after adding more rings in t[1] and if it becomes equal to n then program terminates
      {
      	if( t[ (to+2)%3 ].empty() )               //if 2 towers after the to tower is empty then just choose the tower that is left as 
      		from = ( to+1 ) % 3 ;                 //as it cannot be to tower itself
      	else if( t[ (to+1)%3 ].empty() )
	  		from = ( to+2 ) % 3 ;
	  	else
	  	{		
      		// from = the index of the tower with the smallest ring that has not just been moved: (to+1)%3 or (to+2)%3
      		if ( ( t[ (to+1) %3 ].back() ) < ( t[ (to+2) %3 ].back() ) )
         		from = ( to+1 ) % 3 ;
      		else
         		from = ( to+2 ) % 3 ;
    	}
         
      	// candidate = the ring on top of the t[from] tower
      	candidate = t[from].back() ;
         
      	// to = the index of the closest tower on which the candidate can be placed: (from+1)%3 or (from+2)%3
      	// (compare the candidate with the ring on the closer tower; which tower is "closer" depends on whether n is odd or even)
		if( n%2 == 0 )                        //if n is even
		{
			if ( (t[ (from+2) %3 ].empty()) || (candidate < t[ (from+2) %3 ].back()) )     //if there 2 towers after from tower is empty
         		to = ( from+2 ) % 3 ;                                                      //or candiate is smaller than the 2 towers after from tower 
      		else                                                                       
         		to = ( from+1 ) % 3 ;
		}
		else	                              //if n is odd
		{	   
      		if ( (t[ (from+1) %3 ].empty()) || (candidate < t[ (from+1) %3 ].back()) )      //if there 1 tower afterfrom tower is empty
         		to = ( from+1 ) % 3 ;                                                       //or candidate is smaller than the 1 tower after from tower
      		else
         		to = ( from+2 ) % 3 ;
     	}
      }
   }
   return 0;
}

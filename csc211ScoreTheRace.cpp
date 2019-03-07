#include<iostream>
#include <stdlib.h>
#include <time.h>

/** Title- Score The Race
 *  Description : This is game that user enters the value from A-Z each individual character 
 *                uniquely is a team. Number of teams, and their average is printed on the screen.
 *  Author - Sulbha Aggarwal
 * 
 * Note- My program is lengthy but I am writing comments for every line so that it is easy for you to grade Professor
 * */

using namespace std;

int main() 
{
   while (true) 
   {
      string runners ;
      cout << "Enter the race outcome: ";
      getline(cin, runners) ;
      
      if( runners.compare( "done" ) == 0 )       // If the user entered "done", exit the program
      	  break ;
      
      int numTeams = 0;                        // The number of teams
      int scores[26] = {};                     // scores[i] keeps track of the total score of team i
      int counts[26] = {};                     // counts[i] keeps track of the number of runners on team i
     
      for (int i = 0; i < runners.length(); ++i)     // For each runner in the race,
	  { 
	     int index = runners[i] - 65 ;           // for getting the ascii value of runner at pos i 
         scores[index] += ( i+1 ) ;              // Increase the team's score by the runner's rank (the rank is 1 more than the index)
         
         if( counts[index] == 0 )                // If it's the first runner of that particular team, update the total number of teams
         	numTeams++ ;
         counts[index]++ ;                       // Update the number of runners on the team
      }//end of for loop
      
      int i = 0 ;
      int numRunner = counts[ runners[0] - 65 ] ;
      int size = ( sizeof(counts)/sizeof(int) ) ;
      while( i < size )
      {
      	if( ( counts[i] == 0 ) ||  ( counts [i] == numRunner ) )      // If the teams do not all have the same number of runners,
      		i++ ;
      	else 
      	{
      		cout << "The teams don't have same number of runners." << endl  ;     // Print an error message and ask for input again (go back to the beginning of the loop)
      		break ;
      	}			
      }//end of while loop
      
      if( i != size )        // if the previous while loop did not break and went till the end
      	continue ;
     
      cout << "There are " << numTeams << " teams." << endl ;      // Print the number of teams
      cout << "Each team has " << numRunner << " runners." << endl ;     // Print the number of runners on each team
      
      double winScore = (double)scores[ runners[0]-65 ] / numRunner ;    //Getting the score of first team entered by user 
      char winTeam ;                            //This will keep the track of which team won 
      int index = 0 ;
      
      for( int j = 0 ; j < size ; j++ )    // For each letter from A-Z,
      {
      	if( counts[j] != 0 )               // If that team participated,
      	{
      		 char teamName = j + 65 ;                            //getting th name of the team from its ascii value
      		 double score = (double)scores[j] /numRunner ;       //getting average score of a team
      		 cout << teamName << ": " << score << endl ;         // Print the name of the team and its average score
     
			   if( winScore > score )                            // Also keep track of which team(s) has the best score
			   {
			   		index = j ;
			   		winScore = score ;
			   }
      	}//end of if statement
      }// end of for loop
      
      /*The code below is written just in case if there is a tie then I am picking a random winner
      */
       string winners[10] = {} ;        //This array will store the name of winners
       int pos = 0 ;                    //To go to next index in array if there is more than one winner
       while( index < size )            //Start from the pos index, where we found our first winner go till the end to find a tie
       {
       	if( (double)scores[index] /numRunner == winScore )    //if there is any winner
       	{
		  char teamName = index + 65 ;                        //gettinng the name of the team from it's ascii value
      	  winners[pos] += teamName ;                          //storing the winner in relevant index in the array
		  pos++ ;	                                          
       	}//end of of statement
       	 index++ ;
       }//end of whiel loop
      
       srand ( time(NULL) );             //initialize the random seed
       int RandIndex = rand() % pos ;    //generates a random number between 0 and pos
 	   string str = winners[RandIndex];  //choose the winner randomly
   	   cout << "The wining team is team " << str << " with score " << winScore << endl ;    // Print the name of the winning team and its average score (if it's a tie, you may either pick one arbitrarily or print all of the winners)
   } // end of main while loop
   return 0;
}//end of main 

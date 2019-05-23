#include<iostream>
/*
* Title: 		Shortest Path Recursive
* Description : The goal of this program is to find the shortest way to move throw a weighted 2D array.
                This project uses memoization to efficiently find the solution(not that efficient because still it's recursive).
                Must go through one square on each column.
				Each move can only go one square horizontally or diagonally.
				The 2D array grid is a cylinder, it wraps around.
				The squares are weighted; the number in each square represents the time it takes to travel through the square.
  Author: 		Sulbha Aggarwal
*/
using namespace std ;

const int rows = 5 ;
const int cols = 6 ;

// Returns the cost of the shortest path from the left to the square in row i, column j.
int cost( int i , int j , string path[][cols] )
{
	int weight[rows][cols]  = { 3 , 4 , 1 , 2 , 8 , 6 ,
							    6 , 1 , 8 , 2 , 7 , 4 ,
								5 , 9 , 3 , 9 , 9 , 5 ,
								8 , 4 , 1 , 3 , 2 , 6 , 
								3 , 7 , 2 , 8 , 6 , 4 } ;
								
	int cost1[rows][cols] ;              // stores the Calculated the cost of every square 
	if( j == 0 )                         //base case
	{
		path[i][j] = to_string(i) ;      //if column is zero then initialize the path
		return weight[i][0] ;
	}
	
	int left = cost( i , j-1 , path ) ;
	int up =  cost ( ( i+(rows-1) )%rows , j-1 , path ) ;
	int down = cost ( (i+1)  % rows , j-1 , path ) ;
	
	int min1 = min(min(left,up),down);                //getting the minimum out of left, top or down rows of previous column
	
	//storing the correct path i.e, updating the path matrix
	if( min1 == left )
		path[i][j] = path[i][j-1] + to_string(i) ;
	else if ( min1 == up )
		path[i][j] = path[ ( i+(rows-1)) % rows  ][j-1] + to_string(i) ;
	else
		path[i][j] = path[ (i+1)% rows ][j-1] + to_string(i) ;
		
	cost1[i][j] = min1 + weight[i][j] ;               //storing the minimum cost in the cost matrix
	return cost1[i][j] ;
}

int main() 
{
	int ex[rows] ;
	string path[rows][cols] ;
	for( int i = 0 ; i < rows ; i++ )
		ex[i] = cost( i , cols-1 , path ) ;               // Calling the calculateCost function once for each square in the rightmost column of the grid
	
	
	int min = 0 ;
	for( int i = 1 ; i < rows ; i++ )       
	{
	    if( ex[i] < ex[min] )                             // Check which one has the lowest cost in ex array and storing that row number in min
	        min = i ;
	}
	
	
	cout << "The length of shortest path is " << ex[min] << endl ;                    //priniting shortest path i.e, minimum weight
	cout << "The rows of the path left to right are " << path[min][cols-1] ;            //prinitng shortest path taken to get the minimum weight
	return 0 ;
    //system("PAUSE") ;
	//return EXIT_SCCESS ;
}

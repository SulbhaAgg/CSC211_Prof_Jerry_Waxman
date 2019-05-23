#include<iostream>
//#include<string>

/*
* Title: 		Shortest Path(Non_Recursive)
* Description : The goal of this program is to find the shortest way to move throw a weighted 2D array.
                This project uses memoization to efficiently find the solution.
                Must go through one square on each column.
				Each move can only go one square horizontally or diagonally.
				The 2D array grid is a cylinder, it wraps around.
				The squares are weighted; the number in each square represents the time it takes to travel through the square.
  Author: 		Sulbha Aggarwal
*/

using namespace std ;


int main()
{
	int weight[5][6] = { 3 , 4 , 1 , 2 , 8 , 6 ,
						 6 , 1 , 8 , 2 , 7 , 4 , 
						 5 , 9 , 3 , 9 , 9 , 5 ,
						 8 , 4 , 1 , 3 , 2 , 6 ,
						 3 , 7 , 2 , 8 , 6 , 4 } ;

	int cost[5][6] = {0} ;  // stores the Calculated the cost of every square 
	string path[5][6] ;     //stores the row path at every square
	
	int row = sizeof(weight)/sizeof(weight[0]) ;               //getting the rows of matrix weight
	int col = sizeof(weight[0])/sizeof(weight[0][0]) ;         //getting of column of matrix weight
	
	for( int i = 0 ; i < sizeof(weight)/sizeof(weight[0]) ; i++ )           
	{
		cost[i][0] = weight[i][0] ;                 // Copying the leftmost column of the weight matrix to the cost matrix
		path[i][0] = to_string(i);                  //initializing the leftmost column of the path matrix
	}
	
	int min1 = 0 , left = 0 , up = 0 , down = 0 ;
	
	//Calculating the cost of each square in the column 
	for( int j = 1 ; j < col ; j++ )
	    for( int i = 0 ; i < row ; i++ )
	    {
	        left = cost[i][j-1] ;
	        up = cost[ (i + row-1)%row ][j-1] ;
	        down = cost[ (i+1)%row ][j-1] ;
	        min1 = min( min( up , left ) , down ) ;                        //getting the minimum out of left, top or down rows of previous column
	        
	        //storing the correct path 
	        if( min1 == left )
	            path[i][j] = path[i][j-1] + to_string(i) ;
	        else if( min1 == up )
	            path[i][j] = path[ (i + row-1)%row ][j-1] + to_string(i) ;
	        else
	            path[i][j] = path[ (i+1)%row ][j-1] + to_string(i) ;
	            
	        cost[i][j] = min1 + weight[i][j] ;                             //storing the minimum cost in the cost matrix 
	    }
	
	int min = 0 ;
	for( int i = 1 ; i < row ; i++ )
		if( cost[min][5] > cost[i][5] )                                    //getting the index of the last column which has the minimum weight
			min = i ;                                         
	
	cout << "The length of shortest path is " << cost[min][col-1] << "." ;                     //priniting shortest path i.e, minimum weight
	cout << "\nThe rows of the path from left to right are " << path[min][col-1] << "." ;      //prinitng shortest path taken to get the minimum weight
	
	/*for( int k = 0 ; k < 2 ; k++ )               //this is test code , to see what is in cost and path matrix
	{
		for( int i = 0 ; i < row ; i++ )
		{
			for( int j = 0 ; j < col ; j++ )
			{
				if( k == 0 )
					cout << cost[i][j] << " " ;
				else
					cout << path[i][j] << " " ;
			}
			cout << "\n" ;
		}
		cout << "\n" ;
	}*/

}

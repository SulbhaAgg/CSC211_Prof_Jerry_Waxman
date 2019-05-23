#include<iostream>
/*
* Title: 		Rat Class
* Description : The goal of this project is to create a class which adds, subtracts, multiply and divide two fractions.
				Tjis calass uses various functions and in class and outside class methods to display the data.
				Professor my code is different then your template I didnt look at your template until I was finished.
				I mentioned at lot of comments so that it is easier to nderstand the code.
  Author: 		Sulbha Aggarwal
*/
using namespace std ;

class Rat
{
	private:
		int n;
		int d ;
	
	public:                                          //constructors
		Rat()                                        //Deafault Constructor initializing the instance variables of the class
		{
			n = 0 ;
			d = 1 ;
		}
		
		Rat( int i , int j )                         //paramterized constructor
		{
			n = i ;
			d = j ;
		}
		
		Rat( int i )                                 //1 parameter constructor
		{
			n = i ;
			d = 1 ;
		}
		
		int getN()                                   //accessor dunction for numerator
		{ 
			return n ;
		}
		
		int getD()                                   //accessor dunction for denominator
		{
			return d ;
		}
		
		int setN( int i )                            //mutator method for numerator
		{
			n = i ;
		}
		
		int setD( int i )                            //mutator method for dinominator
		{
			d = i ;
		}
		
		Rat operator+( Rat r )                       //arithmetic operator for +
		{
			//cout << "In operator+\n" ;
			Rat t ;
			t.n = n*r.d + d*r.n ;
			t.d = d*r.d ;
			return t ;
		}
		
		Rat operator-( Rat r )                       //arithmetic operator for - 
		{
			//cout << "In operator-\n" ;
			Rat t ;
			t.n = n*r.d - d*r.n ;
			t.d = d*r.d ;
			return t ;                               
		}
		
		Rat operator*( Rat r )                       //arithmetic operator for /
		{
			//cout << "In operator*\n" ;
			Rat t ;
			t.n = n*r.n ;
			t.d = d*r.d ;
			return t ;
		}
		
		Rat operator/( Rat r )                       //arithmetic operator for /
		{
			//cout << "In operator/\n" ;
			Rat t ;
			t.n = n*r.d ;
			t.d = d*r.n ;
			return t ;
		}
		
		//declaration of ostream as friend
		friend ostream& operator<<( ostream& os, Rat r );
		
		//declaration of istream as friend
		friend istream& operator>>(istream& is, Rat& r ) ;
		
		
} ;

//overwriting left shift operator to print rat object
ostream& operator<<( ostream& os, Rat r )
{
	os <<  r.n << "/" << r.d << endl;
	//return os;
}

//onerwriting right shift operator to assign the rat object numerator and denominator
istream& operator>>( istream& is , Rat& r )
{
	is >> r.n >> r.d ;
	return is ;
}

//This method reduces the fraction for- 10/20 is reduced to 1/2
Rat redFrac( Rat num )
{
	int n = num.getN() ;                             //get the numerator for the rat object by calling rat function for get integer value for numeraor
	int d = num.getD() ;                             //get the denominator for the rat object by calling rat function for get integer value for numeraor
	int min = n<d ? n : d ;                          // getting the minimum value either denominator or numerator
	int gcd = 1 ;                                    // initializing gcd
	for( int i = 2 ; i <= min ; i++ )                //getting the greatest comman denominator of the smallest value out of numerator or denominator
		if( (n%i == 0) && (d%i == 0) )
			gcd = i ;                                 
	
	num.setN(n/gcd) ;                                //setting numerator as the reduced form by dividing by gcd
	num.setD(d/gcd) ;                                //setting denominator as the reduced form by dividing by gcd
	return num ;                                     //returning rat object
}

string mixFrac( Rat num )                            //This function converts improper fraction into mixed Fraction return String
{
	int n = num.getN() ;                             //get the numerator for the rat object by calling rat function for get integer value for numeraor
	int d = num.getD() ;                             //get the denominator for the rat object by calling rat function for get integer value for numeraor
	string frac ;                                    //string holds the mixed fraction
	if( d == 1 || n == 0 )                           //if numerator is 0 or nenomerator is 1 than just pring numerator
	    frac = to_string(n) ;
	else if( n > d )
		frac = to_string(n/d) + " " + to_string(n%d) + "/" + to_string(d) ;      //Do mixed fraction only id numerator > than denominator
	else
		frac = to_string(n) + "/" +to_string(d) ;                                //otherwise do not do anything
	return frac ;
}

int main()
{
	Rat r1( 5 , 2 ) , r2( 3 , 2 ), neg ;                       //created three rat objects, 2 with parameters and              
	
	for( int i = 0 ; i < 3 ; i++ )                             //As we want to test for some special consitions which will be convered in 3 cases
	{
	
		if( i == 1 )                                           //In 2nd  case do this condition
	 	{
	
			r1 = r2 ;                                          // 3/4
			r2 = r1 * r2 ;                                     // 9/4
	 	}	
	 	else if( i == 2 )                                      //In 3rd case do this consition
	 	{
	 		r1 = r2 + (( r1 * r2 ) / r1 ) ;                    // 9/2
	 		r2 = r2 + (( r1 * r2 ) / r1 ) ;                    // 9/2
	 	}
		cout << "\nr1: " << mixFrac(redFrac(r1)) << "\nr2: " << mixFrac(redFrac(r2)) << endl ;    //prinitng out r1 and r2 in mixed fraction form
		cout << "r1 + r2: " << mixFrac(redFrac(r1+r2)) << endl ;                                  //adding r1 and r2
	 
		neg = r1 - r2 ;                                                    
		if( neg.getN() < 0 )                                              //if r2 is grater than r1 and sign is negative
	    	{ 
	        	neg.setN(-neg.getN()) ;                                   //Then jsut take the negative sign off after subtracting them
	        	cout << "r1 - r2: -" << mixFrac(redFrac(neg)) << endl ;   //after getting the lowest form and then after converting 
	    	}                                                             //the lowest form into mixed fraction add the negative signn in front
		else
	    	cout << "r1 - r2: " << mixFrac(redFrac(r1-r2)) << endl ;      //if r2 is < r1 than just subtract
	
		cout << "r1 * r2: " << mixFrac(redFrac(r1*r2)) << endl ;	      //multiplying r1 and r2
		cout << "r1 / r2: " << mixFrac(redFrac(r1/r2)) << endl ;          //diving r1 with r2
	
	
		
	}
	
	

	return 0 ;
	
	//This is an extra code that I wrote before I saw the template but then I realised that we have to manually assign the values to r1 and r2
	/*Rat r1 , r2 ;
	Rat neg ;// mult , div ;
	string mixedFrac ;
	cout << "Enter the two different values for fraction 1 (press enter inbetween) : \n" ; 
	cin >> r1 ;
	cout << "Enter the two different values for fraction 2 (press enter inbetween) : \n" ;
	cin >> r2 ;*/
	
	//this is the code in case r1 or r2 or both are negative in case of multiplication and division
		/*mult = r1 * r2 ;
	div = r1 /  r2 ;
	if( mult.getN() < 0 )
	    {
	        mult.setN(-mult.getN()) ;
	        div.setN(-div.getN()) ;
	        	cout << "r1 * r2: -" << mixFrac(redFrac(mult)) << endl ;
	        	cout <<  "r1 / r2: -" << mixFrac(redFrac(r1/r2)) << endl ;
	    }*/
}


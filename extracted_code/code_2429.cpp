long int gcd ( long int , long int ) ; long int lcm ( long int , long int ) ; int main ( void ) { int t ; long int a , b , g , temp , l ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%ld%ld" , & a , & b ) ; if ( a > b ) { temp = a ; a = b ; b = temp ; } g = gcd ( a , b ) ; l = lcm ( a , b ) ; printf ( "%ld %ld\n" , g , l ) ; } return 0 ; } long int gcd ( long int a , long int b ) { long int i , r1 , r2 ; for ( i = a ; i >= 1 ; i -- ) { r1 = a % i ; if ( r1 == 0 ) { r2 = b % i ; if ( r2 == 0 ) return i ; } } } long int lcm ( long int a , long int b ) { long int i = b , r ; while ( 1 ) { r = b % a ; if ( r == 0 ) return b ; b += i ; } }
long int gcd ( int a , int b ) { if ( b == 0 ) { return a ; } else { gcd ( b , a % b ) ; } return 1 ; } int main ( void ) { int t ; scanf ( "%d" , & t ) ; while ( t > 0 ) { long int a , b ; scanf ( "%ld %ld" , & a , & b ) ; long int g = gcd ( a , b ) ; long int l = ( a * b ) / g ; printf ( "%ld %ld" , g , l ) ; puts ( "" ) ; t -- ; } }
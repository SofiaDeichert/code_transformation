long int gcd ( long int x , long int y ) { if ( x % y == 0 ) return y ; else return gcd ( y , x % y ) ; } int main ( void ) { long int t , a , b , l , g ; scanf ( "%ld" , & t ) ; while ( t -- ) { scanf ( "%ld%ld" , & a , & b ) ; g = gcd ( a , b ) ; l = ( a * b ) / g ; printf ( "%ld %ld\n" , g , l ) ; } return 0 ; }
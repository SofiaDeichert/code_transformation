int gcd ( long int a , long int b ) { if ( b == 0 ) { return a ; } else { return gcd ( b , a % b ) ; } } int main ( ) { int t ; scanf ( "%d" , & t ) ; while ( t -- ) { long int a , b ; scanf ( "%ld %ld" , & a , & b ) ; int g = gcd ( a , b ) ; long int l = ( a * b ) / g ; printf ( "%d %ld\n" , g , l ) ; } }
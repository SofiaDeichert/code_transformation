long gcd ( long a , long b ) { if ( a == b ) { return a ; } if ( a > b ) { return gcd ( a - b , b ) ; } return gcd ( a , b - a ) ; } int main ( ) { int t ; long a , b ; scanf ( "%d" , & t ) ; for ( int i = 0 ; i < t ; i ++ ) { scanf ( "%ld%ld" , & a , & b ) ; int g = gcd ( a , b ) ; int l = a * b / g ; printf ( "%ld %ld\n" , g , l ) ; } return 0 ; }
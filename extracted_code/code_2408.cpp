int gcd ( int a , int b ) { int i ; i = a - 1 ; for ( ; i >= 1 ; i -- ) { if ( ( a % i == 0 ) && ( b % i == 0 ) ) return i ; } } int lcm ( int a , int b ) { int k , o ; o = gcd ( a , b ) ; k = ( b / o ) * a ; return k ; } int main ( ) { int t , a , b , l , m ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d %d" , & a , & b ) ; if ( a == b ) { printf ( "%d %d" , a , a ) ; break ; } else if ( a > b ) { l = gcd ( b , a ) ; m = lcm ( b , a ) ; } else { l = gcd ( a , b ) ; m = lcm ( a , b ) ; } printf ( "%d %d" , l , m ) ; } return 0 ; }
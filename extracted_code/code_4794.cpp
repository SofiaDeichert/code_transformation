int gcd ( int a , int b ) { if ( a % b != 0 ) return gcd ( b , a % b ) ; return b ; } int main ( ) { int t ; scanf ( "%d" , & t ) ; while ( t -- ) { int m , n , g , l ; scanf ( "%d %d" , & m , & n ) ; if ( m > n ) g = gcd ( m , n ) ; else g = gcd ( n , m ) ; l = m * n / g ; printf ( "%d %d\n" , g , l ) ; } return 0 ; }
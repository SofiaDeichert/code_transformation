int gcd ( int a , int b ) { if ( a % b == 0 ) { return b ; } else { return gcd ( b , a % b ) ; } } int main ( ) { int i , t ; for ( i = 0 ; i < t ; i ++ ) { int m , n ; scanf ( "%d%d" , & m , & n ) ; int p = gcd ( m , n ) ; int lcm = ( m * n ) / p ; printf ( "%d " , p ) ; printf ( "%d\n" , lcm ) ; } return 0 ; }
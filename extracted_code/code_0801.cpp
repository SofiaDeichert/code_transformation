int gcd ( int a , int b ) { int c = a % b ; if ( c == 0 ) return b ; else return gcd ( b , c ) ; } int main ( ) { int i , t , n , m , lcm , g ; scanf ( "%d" , & t ) ; for ( i = 0 ; i < t ; i ++ ) { scanf ( "%d%d" , & n , & m ) ; g = gcd ( n , m ) ; lcm = ( n * m ) / g ; printf ( "%d %d\n" , g , lcm ) ; } return 0 ; }
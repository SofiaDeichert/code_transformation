int gcd ( int a , int b ) { if ( b == 0 ) return a ; else return gcd ( b , a % b ) ; } int main ( void ) { int a , b , t , i ; scanf ( "%d" , & t ) ; for ( i = 1 ; i <= t ; i ++ ) { int hcf , lcm ; scanf ( "%d%d" , & a , & b ) ; hcf = gcd ( a , b ) ; lcm = ( a * b ) / hcf ; printf ( "%d %d\n" , hcf , lcm ) ; } return 0 ; }
int main ( void ) { int t , a , b , hcf , lcm ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d %d" , & a , & b ) ; hcf = gcd ( a , b ) ; lcm = ( a * b ) / hcf ; printf ( "%d %d\n" , hcf , lcm ) ; } return 0 ; } int gcd ( int x , int y ) { if ( y == 0 ) { return x ; } else { return gcd ( y , x % y ) ; } }
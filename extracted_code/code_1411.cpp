int gcd ( int x , int y ) { if ( y != 0 ) return gcd ( y , x % y ) ; else return x ; } int lcm ( int x , int y ) { return ( ( x * y ) / gcd ( x , y ) ) ; } int main ( ) { int t , i , g , l , x , y ; scanf ( "%d" , & t ) ; for ( i = 0 ; i < t ; i ++ ) { scanf ( "%d %d" , & x , & y ) ; g = gcd ( x , y ) ; l = lcm ( x , y ) ; printf ( "%d %d\n" , g , l ) ; } return 0 ; }
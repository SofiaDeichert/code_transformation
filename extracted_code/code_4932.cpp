int gcd ( int a , int b ) { if ( a == b ) { return a ; } if ( a == 0 || b == 0 ) { return 0 ; } if ( a > b ) { return gcd ( a - b , b ) ; } else { return gcd ( a , b - a ) ; } } int lcm ( int a , int b ) { return ( a * b ) / gcd ( a , b ) ; } int main ( ) { int t ; scanf ( "%d" , & t ) ; for ( int i = 0 ; i < t ; ++ i ) { int a , b ; scanf ( "%d%d" , & a , & b ) ; printf ( "%d %d\n" , gcd ( a , b ) , lcm ( a , b ) ) ; } return 0 ; }
int main ( ) { int t , a , b , i ; long int gcd = 0 , lcm = 0 ; scanf ( "%d" , & t ) ; while ( t ) { scanf ( "%d" , & a ) ; scanf ( "%d" , & b ) ; for ( i = 2 ; i < a && i < b ; i ++ ) { if ( a % i == 0 && b % i == 0 ) { gcd = i ; } } printf ( "%ld\n" , gcd ) ; lcm = ( a * b ) / gcd ; printf ( "%ld\n" , lcm ) ; t -- ; } return 0 ; }
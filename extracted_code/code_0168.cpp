int main ( ) { int t , a , b , gcd , m , n ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d%d" , & a , & b ) ; m = a ; n = b ; while ( 1 ) { a = a % b ; if ( a == 0 ) { gcd = b ; break ; } b = b % a ; if ( b == 0 ) { gcd = a ; break ; } } printf ( "%d %d" , gcd , ( m * n ) / gcd ) ; } return 0 ; }
int main ( void ) { int t , a , b , c , j , i , gcd , lcm ; scanf ( "%d" , & t ) ; for ( int i = 1 ; i <= t ; i ++ ) { scanf ( "%d" , & a ) ; scanf ( "%d" , & b ) ; if ( a > b ) c = a ; else c = b ; for ( j = 1 ; j <= c / 2 ; j ++ ) { if ( a % j == 0 && b % j == 0 ) { gcd = j ; } } printf ( "%d " , gcd ) ; lcm = ( a * b ) / gcd ; printf ( "%d\n" , lcm ) ; } return 0 ; }
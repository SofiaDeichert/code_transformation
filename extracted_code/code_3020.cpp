int main ( void ) { long a , b , i , n , hcf , lcm , j ; scanf ( "%ld" , & n ) ; while ( n -- ) { scanf ( "%ld %ld" , & a , & b ) ; if ( a > b ) { for ( i = 1 ; i < b ; i ++ ) { if ( a % i == 0 && b % i == 0 ) { hcf = i ; } } } if ( b > a ) { for ( i = 1 ; i < a ; i ++ ) { if ( a % i == 0 && b % i == 0 ) { hcf = i ; } } } for ( j = a ; j <= ( a * b ) ; j ++ ) { if ( j % a == 0 && j % b == 0 ) { lcm = j ; break ; } } printf ( "%ld %ld\n" , hcf , lcm ) ; } return ( 0 ) ; }
int main ( ) { int t , x , y ; long long int a , b , gcd , lcm , no1 , no2 , i , j ; scanf ( "%d" , & t ) ; while ( t -- ) { i = 1 , x = 0 , y = 0 ; scanf ( "%lld %lld" , & a , & b ) ; if ( a > b ) no1 = b , no2 = a ; else no1 = a , no2 = b ; j = no1 ; while ( 1 ) { if ( ( no2 * i ) % no1 == 0 && x == 0 ) { lcm = no2 * i ; x = 1 ; } if ( no1 % j == 0 && no2 % j == 0 && y == 0 ) { gcd = j ; y = 1 ; } j -- ; i ++ ; if ( x == 1 && y == 1 ) break ; } printf ( "%lld %lld\n" , gcd , lcm ) ; } return 0 ; }
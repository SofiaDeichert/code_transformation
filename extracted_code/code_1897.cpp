int main ( void ) { long long int a , b , gcd = 0 , lcm = 0 ; int i , t ; scanf ( "%d\n" , & t ) ; while ( t -- ) { scanf ( "%lld %lld" , & a , & b ) ; lcm = a > b ? a : b ; while ( 1 ) { if ( lcm % a == 0 && lcm % b == 0 ) { break ; } lcm ++ ; } for ( i = 1 ; i <= a && i <= b ; i ++ ) { if ( a % i == 0 && b % i == 0 ) { gcd = i ; } } printf ( "%lld %lld\n" , gcd , lcm ) ; } return 0 ; }
int main ( void ) { int t ; scanf ( "%d" , & t ) ; if ( t > 0 && t <= 1000 ) { for ( int i = 1 ; i <= t ; i ++ ) { long long int n1 , n2 , gcd , lcm ; scanf ( "%lld %lld" , & n1 , & n2 ) ; for ( int j = 1 ; j <= n1 && j <= n2 ; j ++ ) { if ( n1 % j == 0 && n2 % j == 0 ) gcd = j ; } lcm = ( n1 * n2 ) / gcd ; printf ( "%lld %lld\n" , gcd , lcm ) ; } } return 0 ; }
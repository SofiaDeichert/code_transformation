int main ( ) { long long int t , a , b , x , i , hcf , lcm ; scanf ( "%lld" , & t ) ; while ( t -- ) { scanf ( "%lld %lld" , & a , & b ) ; x = 1 ; while ( x <= a && x <= b ) { if ( a % x == 0 && b % x == 0 ) hcf = x ; x ++ ; } printf ( "%lld " , hcf ) ; lcm = ( a * b ) / hcf ; printf ( "%lld\n" , lcm ) ; } }
int main ( ) { int T , i ; scanf ( "%d" , & T ) ; while ( T -- ) { long long int a , b ; long long int gcd = 0 , lcm = 0 ; scanf ( "%lld%lld" , & a , & b ) ; for ( i = 1 ; i <= a && i <= b ; i ++ ) { if ( a % i == 0 && b % i == 0 ) gcd = i ; } lcm = ( a * b ) / gcd ; printf ( "%lld %lld" , gcd , lcm ) ; } return 0 ; }
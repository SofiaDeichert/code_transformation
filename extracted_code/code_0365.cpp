long GCD ( long a , long b ) { if ( b == 0 ) return a ; else return GCD ( b , a % b ) ; } main ( ) { int t ; scanf ( "%d" , & t ) ; while ( t -- ) { long a , b ; scanf ( "%ld%ld" , & a , & b ) ; long gcd = GCD ( a , b ) ; long long lcm = ( a * b ) / gcd ; printf ( "%ld %lld\n" , gcd , lcm ) ; } }
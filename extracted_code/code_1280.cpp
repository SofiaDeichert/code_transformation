int main ( ) { int t , i ; long int l , gcd , lcm , a , b ; scanf ( "%d" , & t ) ; while ( t -- ) { gcd = 1 ; scanf ( "%ld%ld" , & a , & b ) ; l = a < b ? a : b ; for ( i = 1 ; i <= l ; i ++ ) { if ( a % i == 0 && b % i == 0 ) gcd = i ; } lcm = ( a * b ) / gcd ; printf ( "%ld %ld\n" , gcd , lcm ) ; } return ( 0 ) ; }
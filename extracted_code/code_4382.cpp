int main ( ) { long int a , s , d , gcd , lcm ; int t ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%ld %ld" , & a , & s ) ; for ( d = 1 ; d <= a && d <= s ; d ++ ) { if ( a % d == 0 && s % d == 0 ) gcd = d ; } lcm = ( a * s ) / gcd ; printf ( "%ld " , lcm ) ; printf ( " %ld\n" , gcd ) ; } return 0 ; }
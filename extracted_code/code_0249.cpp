int main ( ) { int n ; scanf ( "%d" , & n ) ; int rem , numerator , denominator , gcd , lcm ; for ( int i = 0 ; i < n ; i ++ ) { long int a , b ; scanf ( "%ld%ld" , & a , & b ) ; if ( a > b ) { numerator = a ; denominator = b ; } else { numerator = b ; denominator = a ; } rem = numerator % denominator ; while ( rem != 0 ) { numerator = denominator ; denominator = rem ; rem = numerator % denominator ; } gcd = denominator ; lcm = a * b / gcd ; printf ( "%d %d" , gcd , lcm ) ; } return 0 ; }
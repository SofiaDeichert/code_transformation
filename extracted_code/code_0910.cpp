void main ( ) { long int t , i , a , b , numerator , denominator , remainder , lcm , gcd ; scanf ( "%ld" , & t ) ; while ( t -- ) { scanf ( "%ld %ld" , & a , & b ) ; if ( a > b ) { numerator = a ; denominator = b ; } else { numerator = b ; denominator = a ; } while ( denominator != 0 ) { remainder = denominator ; denominator = numerator % denominator ; numerator = remainder ; } printf ( "%ld %ld\n" , numerator , ( ( a * b ) / numerator ) ) ; } }
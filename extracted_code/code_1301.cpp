void main ( ) { int a , b , c , gcd , lcm , remainder , numerator , denominator , i ; scanf ( "%d" , & a ) ; for ( i = 1 ; i <= a ; i ++ ) { scanf ( "%d %d" , & b , & c ) ; if ( b > c ) { numerator = b ; denominator = c ; } else { numerator = c ; denominator = b ; } remainder = numerator % denominator ; while ( remainder != 0 ) { numerator = denominator ; denominator = remainder ; remainder = numerator % denominator ; } gcd = denominator ; lcm = ( b * c ) / gcd ; printf ( "%d " , gcd ) ; printf ( "%d" , lcm ) ; } }
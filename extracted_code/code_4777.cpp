int main ( ) { int A , B ; int gcd , lcm , remainder , numerator , denominator ; int T , i ; scanf ( "%d" , & T ) ; for ( i = 0 ; i < T ; i ++ ) { scanf ( "%d %d" , & A , & B ) ; if ( A > B ) { numerator = A ; denominator = B ; } else { numerator = B ; denominator = A ; } remainder = numerator % denominator ; while ( remainder != 0 ) { numerator = denominator ; denominator = remainder ; remainder = numerator % denominator ; } gcd = denominator ; lcm = A * B / gcd ; printf ( "%d %d\n" , gcd , lcm ) ; } return 0 ; }
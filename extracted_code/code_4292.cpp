void main ( ) { int min , max , i , gcd , lcm , j , tmp ; printf ( "enter two numbers" ) ; scanf ( "%u%u" , & min , & max ) ; if ( min > max ) { tmp = min ; min = max ; max = tmp ; } for ( i = min ; i >= 1 ; i -- ) { if ( ( min % i == 0 ) && ( max % i == 0 ) ) { break ; } } for ( j = 1 ; j <= max ; j ++ ) { lcm = min * j ; if ( lcm % max == 0 ) break ; } printf ( "lcm=%u\ngcd=%u" , lcm , i ) ; }
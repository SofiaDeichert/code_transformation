main ( ) { int t , i , k , g ; int p = 0 ; scanf ( "%d" , & t ) ; int w [ t * 2 ] ; for ( g = 1 ; g <= t ; g ++ ) { int a , b , hcf , lcm ; scanf ( "%d%d" , & a , & b ) ; if ( a > 1000000 || b > 1000000 && a < 0 || b < 0 ) { printf ( "Improper Entry" ) ; exit ( 0 ) ; } for ( i = 1 ; i <= a ; i ++ ) { if ( a % i == 0 && b % i == 0 ) hcf = i ; } for ( i = a ; i <= a * b ; i ++ ) { if ( i % a == 0 && i % b == 0 ) { lcm = i ; break ; } } w [ p ] = hcf ; w [ p + 1 ] = lcm ; p = p + 2 ; ; } printf ( "\n" ) ; for ( i = 0 ; i < t * 2 ; i ++ ) { printf ( "%d " , w [ i ] ) ; if ( i % 2 != 0 ) printf ( "\n" ) ; } }
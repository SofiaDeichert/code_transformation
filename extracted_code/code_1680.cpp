main ( ) { int i , t , k , gcd ; long a , b , c ; scanf ( "%d" , & t ) ; while ( t -- ) { k = 1 ; scanf ( "%ld" , & a ) ; scanf ( "%ld" , & b ) ; if ( a % 2 != 0 || b % 2 != 0 ) k = 0 ; c = ( a < b ) ? a : b ; if ( c % a == 0 && c % b == 0 ) gcd = c ; else { if ( k == 0 ) for ( i = 1 ; i <= c ; i = i + 2 ) if ( a % i == 0 && b % i == 0 ) gcd = i ; if ( k != 0 ) for ( i = 1 ; i <= c ; i ++ ) if ( a % i == 0 && b % i == 0 ) gcd = i ; } printf ( "%d %ld\n" , gcd , a * b / gcd ) ; } return 0 ; }
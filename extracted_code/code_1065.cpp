void main ( ) { long long int T , a , b , i , j ; long long int c , d ; scanf ( "%lld" , & T ) ; long long int gcd [ T ] , lcm [ T ] ; for ( i = 0 ; i < T ; i ++ ) { scanf ( "%lld %lld" , & a , & b ) ; c = a ; d = b ; while ( c != 0 && d != 0 ) { if ( ( c > d ? c : d ) == c ) c = c % d ; else d = d % c ; } if ( d != 0 ) gcd [ i ] = d ; else gcd [ i ] = c ; lcm [ i ] = ( a / gcd [ i ] ) * b ; } for ( i = 0 ; i < T ; i ++ ) printf ( "%lld %lld\n" , gcd [ i ] , lcm [ i ] ) ; }
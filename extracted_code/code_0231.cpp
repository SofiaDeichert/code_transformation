int main ( ) { int n , i , j , x ; long long a [ 1000 ] ; long long b [ 1000 ] ; long long gcd [ 1000 ] ; long long lcm [ 1000 ] ; long long c [ 1000 ] ; long long d [ 1000 ] ; scanf ( "%d" , & n ) ; for ( i = 0 ; i < n ; i ++ ) { scanf ( "%lld %lld" , & a [ i ] , & b [ i ] ) ; c [ i ] = a [ i ] ; d [ i ] = b [ i ] ; if ( a [ i ] == 0 ) { gcd [ i ] = b [ i ] ; lcm [ i ] = ( a [ i ] * b [ i ] ) / gcd [ i ] ; } else if ( b [ i ] == 0 ) { gcd [ i ] = a [ i ] ; lcm [ i ] = ( a [ i ] * b [ i ] ) / gcd [ i ] ; } else { while ( b [ i ] != 0 ) { x = b [ i ] ; b [ i ] = a [ i ] % b [ i ] ; a [ i ] = x ; } gcd [ i ] = a [ i ] ; lcm [ i ] = ( c [ i ] * d [ i ] ) / gcd [ i ] ; } } for ( j = 0 ; j < n ; j ++ ) { printf ( "%lld %lld\n" , gcd [ j ] , lcm [ j ] ) ; } return 0 ; }
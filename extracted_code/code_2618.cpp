int max ( int a , int b ) { if ( a <= b ) return b ; return a ; } int main ( ) { int T , num , fsum , col , i , j , tsum ; int a [ 100 ] [ 100 ] ; int sums [ 100 ] [ 100 ] [ 2 ] ; scanf ( "%d" , & T ) ; while ( T -- ) { scanf ( "%d" , & num ) ; scanf ( "%d" , & a [ 0 ] [ 0 ] ) ; for ( i = 1 ; i < num ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) scanf ( "%d" , & a [ i ] [ j ] ) ; } fsum = sums [ 0 ] [ 0 ] [ 0 ] = sums [ 0 ] [ 0 ] [ 1 ] = a [ 0 ] [ 0 ] ; for ( i = 1 ; i < num ; i ++ ) { sums [ i ] [ 0 ] [ 0 ] = max ( sums [ i - 1 ] [ 0 ] [ 0 ] , sums [ i - 1 ] [ 0 ] [ 1 ] ) + a [ i ] [ 0 ] ; sums [ i ] [ 0 ] [ 1 ] = 0 ; for ( j = 1 ; j < i ; j ++ ) { sums [ i ] [ j ] [ 0 ] = max ( sums [ i - 1 ] [ j ] [ 0 ] , sums [ i - 1 ] [ j ] [ 1 ] ) + a [ i ] [ j ] ; sums [ i ] [ j ] [ 1 ] = max ( sums [ i - 1 ] [ j - 1 ] [ 0 ] , sums [ i - 1 ] [ j - 1 ] [ 1 ] ) + a [ i ] [ j ] ; } sums [ i ] [ i ] [ 0 ] = 0 ; sums [ i ] [ i ] [ 1 ] = max ( sums [ i - 1 ] [ i - 1 ] [ 0 ] , sums [ i - 1 ] [ i - 1 ] [ 1 ] ) + a [ i ] [ i ] ; } fsum = sums [ 0 ] [ 0 ] [ 0 ] ; for ( i = 0 ; i < num ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) { tsum = ( sums [ i ] [ j ] [ 0 ] ? sums [ i ] [ j ] [ 1 ] : sums [ i ] [ j ] [ 0 ] > sums [ i ] [ j ] [ 1 ] ) ; if ( tsum > fsum ) fsum = tsum ; } } printf ( "%d\n" , fsum ) ; } return 0 ; }
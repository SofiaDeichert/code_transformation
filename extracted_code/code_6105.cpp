int max ( int a , int b ) { if ( a > b ) return a ; else return b ; } int main ( ) { int nCases ; scanf ( "%d" , & nCases ) ; int cnt ; for ( cnt = 0 ; cnt < nCases ; cnt ++ ) { int n ; scanf ( "%d" , & n ) ; int num [ n ] [ n ] ; int i , j ; for ( i = 0 ; i < n ; i ++ ) for ( j = 0 ; j <= i ; j ++ ) { scanf ( "%d" , & num [ i ] [ j ] ) ; } for ( i = 1 ; i < n ; i ++ ) for ( j = 0 ; j <= i ; j ++ ) { if ( j == 0 ) { num [ i ] [ j ] = num [ i ] [ j ] + num [ i - 1 ] [ j ] ; continue ; } if ( i == j ) { num [ i ] [ j ] = num [ i ] [ j ] + num [ i - 1 ] [ j - 1 ] ; continue ; } num [ i ] [ j ] = max ( num [ i ] [ j ] + num [ i - 1 ] [ j - 1 ] , num [ i ] [ j ] + num [ i - 1 ] [ j ] ) ; } int max = 0 ; for ( i = n - 1 ; i < n ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) { if ( num [ i ] [ j ] > max ) max = num [ i ] [ j ] ; } } printf ( "%d\n" , max ) ; } }
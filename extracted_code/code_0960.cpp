int main ( ) { short int n , cse , a [ 100 ] [ 100 ] , b [ 100 ] [ 100 ] ; scanf ( "%d" , & cse ) ; short int i , j ; do { scanf ( "%d" , & n ) ; for ( i = 0 ; i < n ; ++ i ) for ( j = 0 ; j <= i ; ++ j ) scanf ( "%d" , & a [ i ] [ j ] ) ; for ( i = 1 ; i < n ; ++ i ) { b [ i ] [ 0 ] = a [ i ] [ 0 ] ; b [ i ] [ i ] = a [ i ] [ i ] + b [ i - 1 ] [ i - 1 ] ; } for ( i = 2 ; i < n ; ++ i ) for ( j = 1 ; j < i ; ++ j ) b [ i ] [ j ] = a [ i ] [ j ] + max ( a [ i - 1 ] [ j ] , a [ i - 1 ] [ j - 1 ] ) ; j = b [ n - 1 ] [ 0 ] ; for ( i = 1 ; i < n ; ++ i ) j = max ( j , a [ n - 1 ] [ i ] ) ; printf ( "%d" , j ) ; cse -- ; } while ( cse ) ; return 0 ; }
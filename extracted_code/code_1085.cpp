main ( ) { int k , j , i ; int nt , nl ; int a [ 100 ] [ 100 ] ; int p = 0 ; scanf ( "%d" , & nt ) ; int op [ nt ] ; for ( k = 0 ; k < nt ; k ++ ) { scanf ( "%d" , & nl ) ; for ( i = 0 ; i < nl ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) { scanf ( "%d" , & a [ i ] [ j ] ) ; } } for ( i = nl - 2 ; i >= 0 ; i -- ) { for ( j = 0 ; j <= i ; j ++ ) { if ( ( a [ i ] [ j ] + a [ i + 1 ] [ j ] ) > ( a [ i ] [ j ] + a [ i + 1 ] [ j + 1 ] ) ) a [ i ] [ j ] = a [ i ] [ j ] + a [ i + 1 ] [ j ] ; else a [ i ] [ j ] = a [ i ] [ j ] + a [ i + 1 ] [ j + 1 ] ; } op [ k ] = a [ 0 ] [ 0 ] ; } } for ( k = 0 ; k < nt ; k ++ ) printf ( "%d" , op [ k ] ) ; printf ( "\n" ) ; return 0 ; }
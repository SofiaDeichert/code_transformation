void main ( ) { int x , t , n , j ; scanf ( "%d" , & t ) ; for ( ; t > 0 ; t -- ) { scanf ( "%d" , & n ) ; int i , a [ n + 5 ] ; a [ 0 ] = 0 ; for ( i = 1 ; i <= n ; i ++ ) { scanf ( "%d" , & a [ i ] ) ; } for ( j = 1 ; j < n ; ) { if ( a [ j ] > a [ j + 1 ] ) { a [ 0 ] = a [ 0 ] + a [ j + 1 ] ; j ++ ; } else if ( a [ j ] < a [ j + 1 ] ) { a [ 0 ] = a [ 0 ] + a [ j ] ; x = a [ j + 1 ] ; a [ j + 2 ] = a [ j + 1 ] ; j ++ ; } } printf ( "%d\n" , a [ 0 ] ) ; } }
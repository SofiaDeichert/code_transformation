void main ( ) { int a [ 100 ] [ 100 ] , i , k , j , t , ans ; scanf ( "%d" , & t ) ; for ( t ; t > 0 ; t -- ) { scanf ( "%d" , & i ) ; for ( k = 0 ; k < i ; k ++ ) { for ( j = 0 ; j <= k ; j ++ ) scanf ( "%d" , & a [ k ] [ j ] ) ; } for ( k = i - 2 ; k >= 0 ; k -- ) for ( j = 0 ; j <= i ; j ++ ) a [ k ] [ j ] += a [ k + 1 ] [ j ] > a [ k + 1 ] [ j + 1 ] ? a [ k + 1 ] [ j ] : a [ k + 1 ] [ j + 1 ] ; printf ( "%d\n" , a [ 0 ] [ 0 ] ) ; } }
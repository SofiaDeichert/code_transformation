main ( ) { int n , i , j , k = 0 , x , s = 0 , max = - 99 ; int a [ 100 ] [ 100 ] ; scanf ( "%d" , & n ) ; while ( k < n ) { scanf ( "%d" , & x ) ; for ( i = 0 ; i < x ; i ++ ) { for ( j = 0 ; j < x ; j ++ ) a [ i ] [ j ] = 0 ; } for ( i = 0 ; i < x ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) scanf ( "%d" , & a [ i ] [ j ] ) ; } for ( j = 0 ; j < x ; j ++ ) { s = 0 ; for ( i = 0 ; i < x ; i ++ ) { if ( a [ i ] [ j ] < a [ i ] [ j + 1 ] ) s = s + a [ i ] [ j + 1 ] ; else { s = s + a [ i ] [ j ] ; } } if ( s > max ) max = s ; } printf ( "\n%d" , max ) ; k ++ ; } return 0 ; }
main ( ) { int n , t , i , j , a [ 50 ] [ 50 ] , l , sum ; scanf ( "%d" , & n ) ; while ( n -- ) { scanf ( "%d" , & t ) ; sum = 0 ; for ( i = 0 ; i < t ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) { scanf ( "%d" , & a [ i ] [ j ] ) ; } } for ( i = 0 ; i < t ; i ++ ) { l = a [ i ] [ 0 ] ; for ( j = 0 ; j <= i ; j ++ ) { if ( a [ i ] [ j ] > a [ i ] [ 0 ] ) { l = a [ i ] [ j ] ; } } sum = sum + l ; } printf ( "%d\n" , sum ) ; } }
max ( a , b ) { if ( a > b ) return a ; else return b ; } solve ( t ) { int i , j , a [ 102 ] [ 102 ] ; for ( i = 1 ; i <= t ; i ++ ) { for ( j = 1 ; j <= i ; j ++ ) { scanf ( "%d" , & a [ i ] [ j ] ) ; } } for ( i = t - 1 ; i > 0 ; i -- ) { for ( j = 1 ; j <= i ; j ++ ) { a [ i ] [ j ] += max ( a [ i + 1 ] [ j ] , a [ i + 1 ] [ j + 1 ] ) ; } } return a [ 1 ] [ 1 ] ; } main ( ) { int n , f ; scanf ( "%d" , & n ) ; while ( n -- ) { scanf ( "%d" , & f ) ; printf ( "%d \n" , solve ( f ) ) ; } return 0 ; }
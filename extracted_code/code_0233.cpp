void main ( ) { int t ; scanf ( "%d" , & t ) ; while ( t -- ) { int r , i , j ; scanf ( "%d" , & r ) ; int arr [ r ] [ r ] ; for ( i = 0 ; i <= r - 1 ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) arr [ i ] [ j ] = 0 ; } for ( i = 0 ; i <= r - 1 ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) scanf ( "%d" , & arr [ i ] [ j ] ) ; } for ( i = r - 1 ; i >= 1 ; i -- ) { for ( j = 0 ; j <= i - 1 ; j ++ ) { if ( arr [ i ] [ j + 1 ] > arr [ i ] [ j ] ) arr [ i - 1 ] [ j ] += arr [ i ] [ j + 1 ] ; else arr [ i - 1 ] [ j ] += arr [ i ] [ j ] ; } } printf ( "%d\n" , arr [ 0 ] [ 0 ] ) ; } }
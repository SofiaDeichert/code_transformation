int main ( ) { int t , i , j , r ; scanf ( "%d" , & t ) ; while ( t -- ) { int arr [ 100 ] [ 100 ] ; scanf ( "%d" , & r ) ; for ( i = 0 ; i < r ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) scanf ( "%d" , & arr [ i ] [ j ] ) ; } if ( r == 1 ) printf ( "%d" , arr [ 0 ] [ 0 ] ) ; if ( r == 2 ) printf ( "%d" , ( arr [ 1 ] [ 0 ] > arr [ 1 ] [ 1 ] ) ? arr [ 0 ] [ 0 ] + arr [ 1 ] [ 0 ] : arr [ 0 ] [ 0 ] + arr [ 1 ] [ 1 ] ) ; else for ( i = r - 2 ; i > 0 ; i -- ) { for ( j = i ; j >= 0 ; j -- ) { arr [ i ] [ j ] += ( arr [ i + 1 ] [ j ] > arr [ i + 1 ] [ j + 1 ] ) ? arr [ i + 1 ] [ j ] : arr [ i + 1 ] [ j + 1 ] ; } } printf ( "%d" , ( arr [ 1 ] [ 0 ] > arr [ 1 ] [ 1 ] ) ? arr [ 0 ] [ 0 ] + arr [ 1 ] [ 0 ] : arr [ 0 ] [ 0 ] + arr [ 1 ] [ 1 ] ) ; } return 0 ; }
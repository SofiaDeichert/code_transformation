int main ( ) { int arr [ 100 ] [ 100 ] ; int t , i , j , l ; scanf ( "%d" , & t ) ; while ( t ) { scanf ( "%d" , & l ) ; for ( i = 0 ; i < l ; i ++ ) for ( j = 0 ; j <= i ; j ++ ) { scanf ( "%d" , & arr [ i ] [ j ] ) ; } for ( i = l - 2 ; i >= 0 ; i -- ) for ( j = 0 ; j <= i ; j ++ ) { if ( arr [ i + 1 ] [ j ] > arr [ i + 1 ] [ j + 1 ] ) arr [ i ] [ j ] += arr [ i + 1 ] [ j ] ; else arr [ i ] [ j ] += arr [ i + 1 ] [ j + 1 ] ; } printf ( "%d\n" , arr [ 0 ] [ 0 ] ) ; t -- ; } return 0 ; }
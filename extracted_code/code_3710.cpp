int main ( ) { int tt ; scanf ( "%d" , & tt ) ; while ( tt -- ) { int n ; scanf ( "%d" , & n ) ; int arr [ n ] [ n ] ; memset ( arr , 0 , sizeof ( arr ) ) ; for ( int i = 0 ; i < n ; i ++ ) for ( int j = 0 ; j <= i ; j ++ ) scanf ( "%d" , & arr [ i ] [ j ] ) ; for ( int i = n - 2 ; i >= 0 ; i -- ) for ( int j = 0 ; j <= i ; j ++ ) arr [ i ] [ j ] += ( arr [ i + 1 ] [ j ] >= arr [ i + 1 ] [ j + 1 ] ) ? arr [ i + 1 ] [ j ] : arr [ i + 1 ] [ j + 1 ] ; printf ( "%d\n" , arr [ 0 ] [ 0 ] ) ; } return 0 ; }
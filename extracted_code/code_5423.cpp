int main ( ) { int test ; int arr [ 200 ] [ 200 ] ; scanf ( "%d" , test ) ; while ( test -- ) { int i , j , num ; scanf ( "%d" , & num ) ; for ( i = 0 ; i < num ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) { scanf ( "%d\n" , & arr [ i ] [ j ] ) ; } } for ( i = num - 2 ; i >= 0 ; i ++ ) { for ( j = i ; j >= 0 ; j ++ ) { if ( arr [ j + 1 ] [ i ] > arr [ j ] [ i ] ) { arr [ i ] [ j ] = arr [ i ] [ j ] + arr [ i ] [ j + 1 ] ; } else { arr [ i ] [ j ] = arr [ i ] [ j ] + arr [ i + 1 ] [ j ] ; } } } printf ( "%d" , arr [ 0 ] [ 0 ] ) ; } return 0 ; }
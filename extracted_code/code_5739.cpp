int max ( int i , int j ) ; int main ( ) { int t ; scanf ( "%d" , & t ) ; while ( t -- ) { int r , i , j ; scanf ( "%d" , & r ) ; int arr [ r ] [ r ] ; for ( i = 0 ; i < r ; i ++ ) { for ( j = 0 ; j < i + 1 ; j ++ ) { scanf ( "%d" , & arr [ i ] [ j ] ) ; } } for ( i = r - 1 ; i > 0 ; i -- ) { for ( j = 0 ; j < i ; j ++ ) { arr [ i - 1 ] [ j ] = arr [ i - 1 ] [ j ] + max ( arr [ i ] [ j ] , arr [ i ] [ j + 1 ] ) ; } } printf ( "%d\n" , arr [ 0 ] [ 0 ] ) ; } return 0 ; } int max ( int i , int j ) { int k ; i > j ? ( k = i ) : ( k = j ) ; return k ; }
int * * arr ; int * * dp ; int max ( int a , int b ) { return a > b ? a : b ; } int main ( ) { int t , n , i , j ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d" , & n ) ; arr = ( int * * ) malloc ( sizeof ( int * ) * n ) ; dp = ( int * * ) malloc ( sizeof ( int * ) * n ) ; for ( i = 0 ; i < n ; i ++ ) { arr [ i ] = ( int * ) malloc ( sizeof ( int ) * ( i + 1 ) ) ; dp [ i ] = ( int * ) malloc ( sizeof ( int ) * ( i + 1 ) ) ; } for ( i = 0 ; i < n ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) { scanf ( "%d" , & arr [ i ] [ j ] ) ; dp [ i ] [ j ] = 0 ; } } dp [ 0 ] [ 0 ] = arr [ 0 ] [ 0 ] ; for ( i = 1 ; i < n ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) { if ( j == 0 ) dp [ i ] [ j ] = dp [ i - 1 ] [ j ] + arr [ i ] [ j ] ; else if ( j == i ) dp [ i ] [ j ] = dp [ i - 1 ] [ j - 1 ] + arr [ i ] [ j ] ; else dp [ i ] [ j ] = max ( dp [ i - 1 ] [ j ] , dp [ i - 1 ] [ j - 1 ] ) + arr [ i ] [ j ] ; } } int maxi = dp [ n - 1 ] [ 0 ] ; for ( i = 1 ; i < n ; i ++ ) { if ( dp [ n - 1 ] [ i ] > maxi ) maxi = dp [ n - 1 ] [ i ] ; } printf ( "%d\n" , maxi ) ; } return 0 ; }
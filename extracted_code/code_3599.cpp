int dp [ 100 ] [ 100 ] = { - 1 } ; int arr [ 100 ] [ 100 ] = { - 1 } ; int main ( ) { int t ; scanf ( "%d" , & t ) ; int n , ans ; int i , j ; while ( t -- ) { scanf ( "%d" , & n ) ; for ( i = 0 ; i < n ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) scanf ( "%d" , & arr [ i ] [ j ] ) ; for ( j = i + 1 ; j < n ; j ++ ) arr [ i ] [ j ] = - 1 ; } memset ( dp , - 1 , sizeof ( dp [ 0 ] [ 0 ] ) * 100 * 100 ) ; ans = solve ( 0 , 0 , n - 1 ) ; printf ( "%d\n" , ans ) ; } return 0 ; } int solve ( int row , int col , int n ) { if ( row == n ) { return arr [ row ] [ col ] ; } if ( dp [ row ] [ col ] != - 1 ) return dp [ row ] [ col ] ; return dp [ row ] [ col ] = arr [ row ] [ col ] + max ( solve ( row + 1 , col , n ) , solve ( row + 1 , col + 1 , n ) ) ; } int max ( int x , int y ) { if ( x > y ) return x ; return y ; }
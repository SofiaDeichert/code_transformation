int main ( ) { int t , n , j , i ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d" , & n ) ; int k [ n ] [ n ] ; for ( i = 0 ; i < n ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) scanf ( "%d" , & k [ i ] [ j ] ) ; } for ( i = n - 1 ; i >= 1 ; i -- ) { for ( j = i ; j >= 1 ; j -- ) { k [ i - 1 ] [ j - 1 ] = max ( k [ i - 1 ] [ j - 1 ] + k [ i ] [ j ] , k [ i - 1 ] [ j - 1 ] + k [ i ] [ j - 1 ] ) ; } } printf ( "%d\n" , k [ 0 ] [ 0 ] ) ; } return 0 ; }
int max ( int a , int b ) ; int main ( ) { int n ; int t ; int i , j ; scanf ( "%d" , & t ) ; int a [ 100 ] [ 100 ] ; while ( t -- ) { scanf ( "%d" , & n ) ; for ( i = 0 ; i < n ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) { scanf ( "%d" , & a [ i ] [ j ] ) ; } } for ( i = n - 2 ; i >= 0 ; i -- ) { for ( j = 0 ; j <= i ; j ++ ) { a [ i ] [ j ] += max ( a [ i + 1 ] [ j ] , a [ i + 1 ] [ j + 1 ] ) ; } } printf ( "%d\n" , a [ 0 ] [ 0 ] ) ; } return 0 ; } int max ( int a , int b ) { return ( ( a > b ) ? a : b ) ; }
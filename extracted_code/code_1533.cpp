int main ( ) { int t ; scanf ( "%d" , & t ) ; while ( t -- ) { int n ; scanf ( "%d" , & n ) ; int A [ n ] ; int i ; for ( i = 0 ; i < n ; i ++ ) scanf ( "%d" , & A [ i ] ) ; int c , j , k ; c = 0 ; for ( j = 0 ; j < n - 1 ; j ++ ) { for ( k = j ; k < n - 1 ; k ++ ) { if ( A [ k ] <= A [ k + 1 ] ) c ++ ; else break ; } } printf ( "%d\n" , c + n ) ; } return 0 ; }
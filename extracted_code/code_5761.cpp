int main ( ) { int t , n , i ; scanf ( "%d" , & t ) ; for ( i = 1 ; i <= t ; i ++ ) { scanf ( "%d" , & n ) ; int j , c = 0 ; long long int a [ n ] ; for ( j = 1 ; j <= n ; j ++ ) scanf ( "%LLd" , & a [ j ] ) ; for ( i = 1 ; i <= n - 1 ; i ++ ) { for ( j = i ; j <= n - 1 ; j ++ ) { if ( ( a [ j ] < a [ j + 1 ] ) || ( a [ j ] == a [ j + 1 ] ) ) c ++ ; else break ; } } printf ( "%d" , n + c ) ; } return 0 ; }
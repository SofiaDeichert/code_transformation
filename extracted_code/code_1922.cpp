int main ( ) { int t , i , j , n ; int a [ 100000 ] ; long result ; scanf ( "%d" , & t ) ; for ( i = 0 ; i < t ; i ++ ) { result = 0 ; scanf ( "%d" , & n ) ; for ( j = 0 ; j < n ; j ++ ) scanf ( "%d" , & a [ j ] ) ; for ( j = 0 ; j < n - 1 ; j ++ ) { if ( a [ j ] > a [ j + 1 ] ) { result += a [ j + 1 ] ; } else { result += a [ j ] ; } } printf ( "%d\n" , result ) ; } return 0 ; }
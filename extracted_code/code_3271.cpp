int main ( ) { int t , i , j , n , a [ 50000 ] ; scanf ( "%d" , & t ) ; for ( i = 0 ; i < t ; i ++ ) { scanf ( "%d" , n ) ; for ( j = 0 ; j < n ; j ++ ) scanf ( "%d" , & a [ j ] ) ; for ( j = 0 ; j < n - 1 ; j ++ ) { if ( a [ j ] < a [ j + 1 ] ) t = a [ j ] ; } printf ( "%d" , t * n ) ; } return 0 ; }
int main ( ) { int t ; long n , count , i , j ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%ld" , & n ) ; long a [ n ] ; for ( i = 0 ; i < n ; i ++ ) scanf ( "%ld" , & a [ i ] ) ; count = n ; for ( i = 0 ; i < n ; i ++ ) { if ( a [ i ] != 0 ) { for ( j = i + 1 ; j < n ; j ++ ) { if ( a [ j ] > a [ i ] ) { count += 1 ; a [ j ] = 0 ; break ; } } } } printf ( "%ld\n" , count ) ; } return 0 ; }
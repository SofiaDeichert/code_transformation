int main ( ) { int t , N , a [ 101 ] ; scanf ( "%d" , & t ) ; int i , j , k ; for ( i = 1 ; i <= t ; i ++ ) { scanf ( "%d" , & N ) ; int count = N ; for ( j = 1 ; j <= N ; j ++ ) { scanf ( "%d" , & a [ j ] ) ; } for ( j = 1 ; j <= N ; j ++ ) { for ( k = 0 ; k <= N ; k ++ ) { if ( a [ k - 1 ] <= a [ k ] ) count ++ ; if ( a [ k - 1 ] > a [ k ] ) break ; } } printf ( "%d\n" , count ) ; return 0 ; } }
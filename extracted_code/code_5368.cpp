int main ( void ) { long long t , count , i , j , a [ 100000 ] , n ; scanf ( "%lld" , & t ) ; while ( t -- != 0 ) { scanf ( "%lld" , & n ) ; for ( i = 0 ; i < n ; i ++ ) scanf ( "%lld" , & a [ i ] ) ; count = 0 ; for ( i = 0 ; i < n ; i ++ ) { for ( j = i + 1 ; j < n ; j ++ ) { if ( a [ i ] < a [ j ] && a [ j ] > a [ j - 1 ] ) { count ++ ; } else break ; } } printf ( "%lld\n" , count + n ) ; } return 0 ; }
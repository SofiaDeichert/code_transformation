int main ( ) { int t , n , i , a [ 50000 ] , m , j , b [ 50000 ] ; scanf ( "%d" , & t ) ; for ( j = 0 ; j < t ; j ++ ) { scanf ( "%d" , & n ) ; for ( i = 0 ; i < n ; i ++ ) { scanf ( "%d" , & a [ i ] ) ; } m = a [ 0 ] ; for ( i = 1 ; i < n ; i ++ ) { if ( a [ i ] < m ) m = a [ i ] ; } b [ j ] = m * ( n - 1 ) ; } for ( j = 0 ; j < t ; j ++ ) printf ( "%d\n" , b [ j ] ) ; return 0 ; }
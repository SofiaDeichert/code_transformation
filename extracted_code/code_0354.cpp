int main ( ) { int n , i , a , j ; scanf ( "%d" , & n ) ; for ( i = 0 ; i < n ; i ++ ) { scanf ( "%d" , & a ) ; long long int b [ 50500 ] , m ; for ( j = 0 ; j < a ; j ++ ) scanf ( "%lld" , & b [ j ] ) ; m = b [ 0 ] ; for ( j = 0 ; j < a ; j ++ ) { if ( b [ j ] < m ) m = b [ j ] ; } printf ( "\n%lld" , m * ( a - 1 ) ) ; } return 0 ; }
int main ( ) { long long int t , n , j , i , sum = 0 , temp ; scanf ( "%lld" , & t ) ; for ( i = 0 ; i < t ; i ++ ) { scanf ( "%lld" , & n ) ; int array [ n ] ; for ( j = 0 ; j < n ; j ++ ) scanf ( "%lld" , & array [ j ] ) ; for ( j = 1 ; j < n ; j ++ ) { if ( array [ 0 ] > array [ j ] ) { temp = array [ j ] ; array [ j ] = array [ 0 ] ; array [ 0 ] = temp ; } } printf ( "%lld\n" , array [ 0 ] * ( n - 1 ) ) ; } return 0 ; }
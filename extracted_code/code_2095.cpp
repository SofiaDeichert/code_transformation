int main ( ) { int t , i , n , min , a [ 50000 ] ; long long int sum ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d" , & n ) ; sum = n - 1 ; for ( i = 0 ; i < n ; i ++ ) { scanf ( "%d" , & a [ i ] ) ; } min = a [ 0 ] ; for ( i = 1 ; i < n ; i ++ ) { if ( min > a [ i ] ) { min = a [ i ] ; } } printf ( "%lld\n" , sum * min ) ; } return 0 ; }
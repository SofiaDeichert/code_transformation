int main ( ) { long long int n , t , i , min , arr [ 50000 ] ; scanf ( "%lld" , & t ) ; while ( t -- ) { scanf ( "%lld" , & n ) ; for ( i = 0 ; i < n ; i ++ ) scanf ( "%lld" , & arr [ i ] ) ; min = 99999 ; for ( i = 0 ; i < n ; i ++ ) { if ( arr [ i ] < min ) min = arr [ i ] ; } printf ( "%lld\n" , min * ( n - 1 ) ) ; } return 0 ; }
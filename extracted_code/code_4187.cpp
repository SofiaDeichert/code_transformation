int main ( ) { long long int t , i , ans , n , a [ 50000 ] , min ; scanf ( "%lld" , & t ) ; while ( t -- ) { scanf ( "%lld" , & n ) ; ans = 0 ; min = 100001 ; for ( i = 0 ; i < n ; i ++ ) { scanf ( "%lld" , & a [ i ] ) ; if ( min > a [ i ] ) { min = a [ i ] ; } } ans = min * ( n - 1 ) ; printf ( "%lld\n" , ans ) ; } return 0 ; }
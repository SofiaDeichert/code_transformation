int main ( ) { int t , n , i , min ; long long int s ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d" , & n ) ; int a [ n ] ; for ( i = 0 ; i < n ; i ++ ) scanf ( "%d" , & a [ i ] ) ; min = a [ 0 ] ; for ( i = 0 ; i < n ; i ++ ) { if ( min > a [ i ] ) min = a [ i ] ; } s = min * ( n - 1 ) ; printf ( "%llu\n" , s ) ; } return 0 ; }
int main ( ) { int i , tcase , min ; scanf ( "%d" , & tcase ) ; while ( tcase -- ) { int n ; scanf ( "%d" , & n ) ; int a [ n ] ; for ( i = 0 ; i < n ; i ++ ) scanf ( "%d" , & a [ i ] ) ; min = a [ 0 ] ; for ( i = 1 ; i < n ; i ++ ) if ( a [ i ] < min ) min = a [ i ] ; printf ( "%d\n" , min * ( n - 1 ) ) ; } return 0 ; }
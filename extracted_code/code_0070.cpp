int main ( ) { int testcase ; scanf ( "%d" , & testcase ) ; while ( testcase -- ) { int a [ 100001 ] , i , n , j , k , ans ; scanf ( "%d" , & n ) ; for ( i = 0 ; i < n ; i ++ ) scanf ( "%d" , & a [ i ] ) ; int min = a [ 0 ] , max = a [ 0 ] ; for ( i = 1 ; i < n ; i ++ ) { if ( min >= a [ i ] ) min = a [ i ] ; } ans = ( n - 1 ) * min ; printf ( "%d\n" , ans ) ; } return 0 ; }
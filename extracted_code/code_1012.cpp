int main ( ) { int t , n , a , min , i ; long long ans ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d" , & n ) ; scanf ( "%d" , & a ) ; min = a ; for ( i = 0 ; i < n - 1 ; i ++ ) { scanf ( "%d" , & a ) ; if ( min > a ) min = a ; } ans = min * ( n - 1 ) ; printf ( "%lld\n" , ans ) ; } return 0 ; }
int main ( ) { int t ; long i , n , num , min ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d" , & n ) ; scanf ( "%ld" , & min ) ; for ( i = 1 ; i < n ; i ++ ) { scanf ( "%ld" , & num ) ; min = ( num < min ) ? num : min ; } printf ( "%lld\n" , ( long long ) ( min * ( n - 1 ) ) ) ; } return 0 ; }
int main ( ) { int t ; scanf ( "%d" , & t ) ; while ( t -- ) { long long int p , n , i ; scanf ( "%lld" , & n ) ; int min = 200000 ; for ( i = 0 ; i < n ; i ++ ) { scanf ( "%lld" , & p ) ; if ( min > p ) min = p ; } long long int q ; q = min * ( n - 1 ) ; printf ( "%lld\n" , q ) ; } return 0 ; }
int main ( ) { int t ; scanf ( "%d" , & t ) ; while ( t -- ) { int n ; scanf ( "%d" , & n ) ; int i , c ; long long int min = 999999 ; for ( i = 0 ; i < n ; i ++ ) { scanf ( "%d" , & c ) ; if ( min > c ) min = c ; } long long int mul = min * ( n - 1 ) ; printf ( "%lld\n" , mul ) ; } return 0 ; }
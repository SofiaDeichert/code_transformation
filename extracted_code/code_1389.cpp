int main ( ) { int t , n ; long long int min , temp ; scanf ( "%d\n" , & t ) ; while ( t > 0 ) { scanf ( "%d\n" , & n ) ; scanf ( "lld" , & min ) ; for ( int i = 1 ; i < n ; i ++ ) { scanf ( "%lld" , & temp ) ; if ( min > temp ) min = temp ; } printf ( "%lld\n" , min * ( n - 1 ) ) ; t -- ; } }
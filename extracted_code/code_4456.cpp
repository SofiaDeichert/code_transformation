int main ( ) { int t ; scanf ( "%d" , & t ) ; while ( t -- ) { long long int cost , i ; cost = 0 ; long long int n ; scanf ( "%lld" , & n ) ; int a [ n ] ; for ( i = 0 ; i < n ; i ++ ) scanf ( "%d" , & a [ i ] ) ; int min = 99999 ; for ( i = 0 ; i < n ; i ++ ) { if ( a [ i ] < min ) { min = a [ i ] ; } } printf ( "%lld\n" , min * n ) ; } }
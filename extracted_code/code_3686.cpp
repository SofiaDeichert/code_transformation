int main ( ) { long long int t , n , s , i , j ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%lld" , & n ) ; long long int arr [ n ] ; for ( i = 0 ; i < n ; i ++ ) { scanf ( "%lld" , & arr [ i ] ) ; } for ( i = 0 ; i < n ; i ++ ) { if ( arr [ i ] > arr [ i + 1 ] ) { s = s + arr [ i + 1 ] ; } else { s = s + arr [ i ] ; } } printf ( "%lld\n" , s ) ; s = 0 ; } }
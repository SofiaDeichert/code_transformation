int main ( ) { long long int a [ 100 ] , n ; int test , t , i , j ; scanf ( "%d" , & test ) ; while ( test -- ) { scanf ( "%lld" , & n ) ; for ( i = 0 ; i < n ; i ++ ) { scanf ( "%lld" , & a [ i ] ) ; } for ( i = 0 ; i < n ; i ++ ) { for ( j = i + 1 ; j < n ; j ++ ) { if ( a [ i ] > a [ j ] ) { t = a [ i ] ; a [ i ] = a [ j ] ; a [ j ] = t ; } } } printf ( "%lld\n" , ( a [ 0 ] * ( n - 1 ) ) ) ; } }
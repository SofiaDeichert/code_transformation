int main ( ) { int t ; scanf ( "%d" , & t ) ; while ( t -- ) { long long int prev = 100001 , n , a [ 100001 ] , ai , i ; scanf ( "%lld" , & n ) ; for ( i = 1 ; i <= n ; i ++ ) a [ i ] = 1 ; for ( i = 1 ; i <= n ; i ++ ) { scanf ( "%lld" , & ai ) ; if ( ai >= prev ) a [ i ] = a [ i - 1 ] + 1 ; prev = ai ; } for ( ai = 0 , i = 1 ; i <= n ; i ++ ) ai += a [ i ] ; printf ( "%lld\n" , ai ) ; } return 0 ; }
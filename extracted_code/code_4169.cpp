int main ( ) { int t , n , i ; long long ans , temp ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d" , & n ) ; long long a [ n ] ; temp = ans = 1 ; for ( i = 0 ; i < n ; ++ i ) scanf ( "%lld" , & a [ i ] ) ; for ( i = n - 1 ; i > 0 ; i -- ) { if ( a [ i ] > a [ i - 1 ] ) { temp ++ ; ans += temp ; } else { temp = 1 ; ans += 1 ; } } printf ( "%lld\n" , ans ) ; } return 0 ; }
void code ( ) { int n , i , k ; k = 1 ; long long int ans = 0 ; scanf ( "%d" , & n ) ; long long int a [ n ] ; for ( i = 0 ; i < n ; i ++ ) { scanf ( "%lld" , & a [ i ] ) ; } for ( i = 0 ; i < n - 1 ; i ++ ) { if ( a [ i + 1 ] >= a [ i ] ) k ++ ; else { k = ( k * ( k + 1 ) ) / 2 ; ans = ans + k ; k = 1 ; } } k = ( k * ( k + 1 ) ) / 2 ; ans = ans + k ; printf ( "%lld\n" , ans ) ; return ; } int main ( ) { int t , i ; scanf ( "%d" , & t ) ; for ( i = 0 ; i < t ; i ++ ) { code ( ) ; } return 0 ; }
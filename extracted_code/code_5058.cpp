int main ( ) { int t , n , i ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d" , & n ) ; long long int a [ n ] ; for ( i = 0 ; i < n ; i ++ ) a [ i ] = 0 ; for ( i = 0 ; i < n ; i ++ ) { scanf ( "%d" , & a [ i ] ) ; } int count = 1 , ans = 0 ; for ( i = 1 ; i < n ; i ++ ) { if ( a [ i ] >= a [ i - 1 ] ) count ++ ; else { ans += ( count * ( count - 1 ) ) / 2 ; count = 1 ; } } ans += ( ( count * ( count - 1 ) ) / 2 ) ; ans += n ; printf ( "%d\n" , ans ) ; } return 0 ; }
int main ( ) { int t ; scanf ( "%d" , & t ) ; while ( t -- ) { int n ; scanf ( "%d" , & n ) ; int i ; int a [ n ] , length [ n ] ; int count = 0 , len ; int ans = n ; for ( i = 0 ; i < n ; i ++ ) { scanf ( "%d" , & a [ i ] ) ; length [ i ] = 0 ; } for ( i = 1 ; i < n ; i ++ ) { if ( a [ i ] >= a [ i - 1 ] ) { len = 1 ; while ( a [ i ] >= a [ i - 1 ] ) { i ++ ; len ++ ; } length [ count ] = len ; count ++ ; } } for ( i = 0 ; i < count ; i ++ ) { ans = ans + ( length [ i ] * ( length [ i ] - 1 ) ) / 2 ; } printf ( "%d\n" , ans ) ; } return 0 ; }
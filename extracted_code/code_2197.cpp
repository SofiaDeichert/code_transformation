int main ( void ) { int t ; scanf ( "%d" , & t ) ; while ( t -- ) { int n ; scanf ( "%d" , & n ) ; int a [ n ] ; for ( int i = 0 ; i < n ; i ++ ) { scanf ( "%d" , & a [ i ] ) ; } int j = 1 ; int cost = 0 ; for ( int i = 0 ; i < n ; i ++ ) { if ( j > ( n - 1 ) ) break ; if ( a [ i ] < a [ j ] && a [ i ] != - 1 && a [ j ] != - 1 ) { cost += a [ i ] ; a [ j ] = - 1 ; } else if ( a [ i ] >= a [ j ] && a [ i ] != - 1 && a [ j ] != - 1 ) { cost += a [ j ] ; a [ i ] = - 1 ; } j ++ ; } printf ( "%d\n" , cost ) ; } return 0 ; }
int main ( ) { int n , i ; scanf ( "%d" , & n ) ; printf ( "\n" ) ; int ans [ n ] ; for ( i = 0 ; i < n ; i ++ ) { int sum = 0 ; int tsum = 0 ; int k , j , lines , no , column ; column = 1 ; scanf ( "%d" , & lines ) ; printf ( "\n" ) ; for ( k = 1 ; k <= lines ; k ++ ) { tsum = sum ; for ( j = 1 ; j <= k ; j ++ ) { scanf ( "%d" , & no ) ; if ( column == j ) { tsum = sum + no ; } else if ( column + 1 == j ) { if ( sum + no > tsum ) { tsum = sum + no ; column ++ ; } } } sum = tsum ; printf ( "\n" ) ; } ans [ i ] = sum ; } for ( i = 0 ; i < n ; i ++ ) { printf ( "%d\n" , ans [ i ] ) ; } return 0 ; }
int memo [ 105 ] [ 105 ] ; int path ( int no [ 105 ] [ 105 ] , int row , int col , int tot ) { if ( memo [ row ] [ col ] != - 1 ) return memo [ row ] [ col ] ; if ( row == tot - 1 ) return no [ row ] [ col ] ; return ( no [ row ] [ col ] + max ( path ( no , row + 1 , col , tot ) , path ( no , row + 1 , col + 1 , tot ) ) ) ; } int main ( ) { int n , i ; memset ( memo , - 1 , sizeof ( memo ) ) ; scanf ( "%d" , & n ) ; int ans [ n ] ; int no [ 105 ] [ 105 ] ; int k , j , lines ; for ( i = 0 ; i < n ; i ++ ) { scanf ( "%d" , & lines ) ; if ( lines <= 0 ) break ; for ( k = 0 ; k < lines ; k ++ ) { for ( j = 0 ; j <= k ; j ++ ) { scanf ( "%d" , & no [ k ] [ j ] ) ; } } ans [ i ] = path ( no , 0 , 0 , lines ) ; } for ( i = 0 ; i < n ; i ++ ) { printf ( "%d\n" , ans [ i ] ) ; } return 0 ; }
int main ( void ) { int t , n , i , j , ctr , f = 0 ; long int a [ 100000 ] ; scanf ( "%d" , & t ) ; while ( t -- ) { ctr = 0 ; scanf ( "%d" , & n ) ; for ( i = 0 ; i < n ; i ++ ) { scanf ( "%d" , & a [ i ] ) ; } for ( i = 1 ; i < n ; i ++ ) { if ( a [ i ] > a [ i - 1 ] ) f ++ ; else { ctr = ctr + ( f * ( f + 1 ) ) / 2 ; f = 0 ; } } if ( f != 0 ) { ctr = ctr + ( f * ( f + 1 ) ) / 2 ; f = 0 ; } ctr = ctr + n ; printf ( "%d\n" , ctr ) ; } return 0 ; }
int main ( ) { int t , n , s = 0 , f = 0 , x , temp , p ; scanf ( "%d" , & t ) ; if ( t >= 1 && t <= 10 ) { while ( t ) { scanf ( "%d" , & n ) ; p = n ; if ( n >= 2 && n <= 50000 ) { int a [ n ] ; for ( int i = 0 ; i < n ; i ++ ) { scanf ( "%d" , & a [ i ] ) ; } for ( int i = 0 ; i < n ; i ++ ) { if ( i < n && i + 1 < n ) { if ( ( a [ i ] >= 1 && a [ i ] <= 100000 ) && ( a [ i + 1 ] >= 1 && a [ i + 1 ] <= 100000 ) ) { if ( a [ i ] > a [ i + 1 ] ) { s += a [ i + 1 ] ; a [ i ] = a [ i + 1 ] ; } else if ( a [ i ] < a [ i + 1 ] ) { s += a [ i ] ; a [ i + 1 ] = a [ i ] ; } } else { f = 1 ; printf ( "%d\n" , s ) ; break ; } } } if ( f != 1 ) { printf ( "%d\n" , s ) ; } } else { scanf ( "%d" , & x ) ; } s = 0 ; f = 0 ; t -- ; } } }
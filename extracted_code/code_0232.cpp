int T , N ; int arr [ 101 ] [ 101 ] ; int max ( int t1 , int t2 ) { if ( t1 > t2 ) return t1 ; else return t2 ; } int solve ( int i , int j ) { int t , t1 , t2 ; if ( i >= N ) return 0 ; t1 = solve ( i + 1 , j ) ; t2 = solve ( i + 1 , j + 1 ) ; t = max ( t1 , t2 ) + arr [ i ] [ j ] ; return t ; } int main ( void ) { int i , j ; scanf ( "%d" , & T ) ; while ( T ) { scanf ( "%d" , & N ) ; for ( i = 0 ; i < N ; i ++ ) for ( j = 0 ; j <= i ; j ++ ) scanf ( "%d" , & arr [ i ] [ j ] ) ; printf ( "%d\n" , solve ( 0 , 0 ) ) ; T -- ; } return 0 ; }
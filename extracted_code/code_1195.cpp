int n ; int arr [ 100 ] [ 100 ] ; int path ( int i , int j ) { if ( i + 1 == n - 1 ) { int sum1 = arr [ i ] [ j ] + arr [ i + 1 ] [ j ] ; int sum2 = arr [ i ] [ j ] + arr [ i + 1 ] [ j + 1 ] ; if ( sum1 > sum2 ) return sum1 ; return sum2 ; } if ( path ( i + 1 , j ) > path ( i + 1 , j + 1 ) ) return ( arr [ i ] [ j ] + path ( i + 1 , j ) ) ; return ( arr [ i ] [ j ] + path ( i + 1 , j + 1 ) ) ; } int main ( void ) { int T ; scanf ( "%d" , & T ) ; while ( T > 0 ) { scanf ( "%d" , & n ) ; int k , m ; for ( k = 0 ; k < n ; k ++ ) { for ( m = 0 ; m <= k ; m ++ ) scanf ( "%d" , & arr [ k ] [ m ] ) ; } printf ( "%d\n" , path ( 0 , 0 ) ) ; T -- ; } return 0 ; }
int main ( ) { int t , n , m , j ; int * * p ; scanf ( "%d" , & t ) ; while ( t > 0 ) { scanf ( "%d" , & n ) ; m = 0 ; p = ( int * * ) malloc ( sizeof ( int * ) * n ) ; while ( m < n ) { p [ m ] = ( int * ) malloc ( sizeof ( int ) * ( m + 1 ) ) ; m ++ ; } for ( m = 0 ; m < n ; m ++ ) { for ( j = 0 ; j < m + 1 ; j ++ ) { scanf ( "%d" , & p [ m ] [ j ] ) ; } } for ( m = n - 1 ; m > 0 ; m -- ) { for ( j = 0 ; j < m ; j ++ ) { if ( p [ m ] [ j ] > p [ m ] [ j + 1 ] ) { p [ m - 1 ] [ j ] += p [ m ] [ j ] ; } else { p [ m - 1 ] [ j ] += p [ m ] [ j + 1 ] ; } } } printf ( "%d\n" , p [ 0 ] [ 0 ] ) ; m = 0 ; while ( m < n ) { free ( p [ m ] ) ; m ++ ; } free ( p ) ; t -- ; } }
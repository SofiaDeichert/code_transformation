int main ( ) { int t , j , k , l , m , r , a [ 99 ] [ 99 ] ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d" , & r ) ; for ( j = 0 ; j < r ; j ++ ) for ( k = 0 ; k <= j ; k ++ ) scanf ( "%d" , & a [ j ] [ k ] ) ; l = r - 2 ; while ( l >= 0 ) { m = 0 ; while ( m <= l ) { a [ l ] [ m ] += ( a [ l + 1 ] [ m ] > a [ l + 1 ] [ m + 1 ] ? a [ l + 1 ] [ m ] : a [ l + 1 ] [ m + 1 ] ) ; m ++ ; } l -- ; } printf ( "%d\n" , a [ 0 ] [ 0 ] ) ; } return 0 ; }
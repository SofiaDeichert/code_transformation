int main ( ) { int j , l , a [ 100 ] [ 100 ] , s , sm , t , n ; scanf ( "%d" , & n ) ; for ( j = 1 ; j < n + 1 ; j ++ ) { scanf ( "%d" , & l ) ; while ( l > 100 ) { scanf ( "%d" , & l ) ; } for ( s = 1 ; s <= ( l * ( l + 1 ) ) / 2 ; s ++ ) { scanf ( "%d" , & a [ j ] [ s ] ) ; while ( a [ j ] [ s ] > 100 ) { scanf ( "%d" , & a [ j ] [ s ] ) ; } } int so = 0 ; for ( t = 1 ; t < l + 1 ; t ++ ) { so = so + a [ j ] [ t ] ; } sm = so ; for ( t = l + 1 ; t <= ( l * ( l + 1 ) ) / 2 ; t ++ ) { so = so - a [ j ] [ t - l ] + a [ j ] [ t ] ; if ( so > sm ) { sm = so ; } } printf ( "%d\n" , sm ) ; } return ( 0 ) ; }
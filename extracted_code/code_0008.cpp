int n , a [ 100 ] [ 100 ] , cache [ 100 ] [ 100 ] ; int maxFromBottom ( int i , int j ) { if ( i < 0 ) return 0 ; if ( cache [ i ] [ j ] != - 1 ) return cache [ i ] [ j ] ; int path1 = 0 ; if ( j != 0 ) path1 = maxFromBottom ( i - 1 , j - 1 ) ; int path2 = maxFromBottom ( i - 1 , j ) ; int max = ( path1 > path2 ? path1 : path2 ) ; cache [ i ] [ j ] = a [ i ] [ j ] + max ; return a [ i ] [ j ] + max ; } int main ( void ) { int t , i , j , k ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d" , & n ) ; k = 0 ; for ( i = 0 ; i < 100 ; i ++ ) for ( j = 0 ; j < 100 ; j ++ ) cache [ i ] [ j ] = - 1 ; for ( i = 0 ; i < n ; i ++ ) for ( j = 0 ; j <= i ; j ++ ) scanf ( "%d" , & a [ i ] [ j ] ) ; for ( i = 0 ; i < n ; i ++ ) { j = maxFromBottom ( n - 1 , i ) ; if ( k < j ) k = j ; } printf ( "%d\n" , k ) ; } return 0 ; }
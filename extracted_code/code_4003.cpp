int hash [ 101 ] [ 101 ] ; int a [ 101 ] [ 101 ] ; int n ; void debug ( int i , int j ) { int p , q ; printf ( "i==>%d j==>%d\n" , i , j ) ; for ( p = 0 ; p < n ; p ++ ) { for ( q = 0 ; q <= p ; q ++ ) { printf ( "%d " , a [ p ] [ q ] ) ; } printf ( "\n" ) ; } return ; } int func ( int i , int j ) { int p , q ; if ( i >= n ) { return 0 ; } else if ( hash [ i ] [ j ] == 1 ) { return a [ i ] [ j ] ; } else { p = func ( i + 1 , j ) ; q = func ( i + 1 , j + 1 ) ; a [ i ] [ j ] += p > q ? p : q ; hash [ i ] [ j ] = 1 ; return a [ i ] [ j ] ; } } int main ( ) { int i , j , ans , cases ; scanf ( "%d" , & cases ) ; while ( cases -- ) { scanf ( "%d" , & n ) ; for ( i = 0 ; i < n ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) { scanf ( "%d" , & a [ i ] [ j ] ) ; hash [ i ] [ j ] = 0 ; } } ans = func ( 0 , 0 ) ; printf ( "%d\n" , ans ) ; } return 0 ; }
int main ( ) { int n , l , i , j , a [ 100 ] [ 100 ] , sum = 0 ; scanf ( "%d" , & n ) ; while ( n -- ) { scanf ( "%d" , & l ) ; for ( i = 1 ; i <= l ; i ++ ) for ( j = 1 ; j <= i ; j ++ ) scanf ( "%d " , & a [ i ] [ j ] ) ; printf ( "\n" ) ; i = j = 1 ; sum = a [ i ] [ j ] ; while ( i <= l ) { if ( a [ i + 1 ] [ j ] > a [ i + 1 ] [ j + 1 ] ) { sum += a [ i + 1 ] [ j ] ; i ++ ; } else { sum += a [ i + 1 ] [ j + 1 ] ; i ++ ; j ++ ; } } printf ( "%d\n" , sum ) ; } return 0 ; }
int main ( ) { int a [ 100 ] [ 100 ] = { 0 , 0 } ; int i , l , t , j , cases , ccnt ; scanf ( "%d" , & cases ) ; for ( ccnt = 0 ; ccnt < cases ; ccnt ++ ) { scanf ( "%d" , & l ) ; getchar ( ) ; for ( i = 0 ; i < l ; i ++ ) for ( t = 0 ; t <= i ; t ++ ) { a [ i ] [ t ] = getchar ( ) - '0' ; getchar ( ) ; } for ( i = l - 2 ; i >= 0 ; i -- ) { for ( t = 0 ; t <= i ; t ++ ) { a [ i ] [ t ] += ( a [ i + 1 ] [ t ] >= a [ i + 1 ] [ t + 1 ] ) ? a [ i + 1 ] [ t ] : a [ i + 1 ] [ t + 1 ] ; } } printf ( "%d\n" , a [ 0 ] [ 0 ] ) ; } return 0 ; }
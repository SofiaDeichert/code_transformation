int main ( ) { int i , j , T , N , curr , c , d ; scanf ( "%d" , & T ) ; while ( T -- ) { scanf ( "%d" , & N ) ; int a [ N ] [ N ] ; for ( i = 1 ; i <= N ; i ++ ) { for ( j = 1 ; j <= i ; j ++ ) scanf ( "%d" , & a [ N ] [ N ] ) ; } for ( i = N - 2 ; i >= 0 ; i -- ) { for ( j = i ; j >= 0 ; j -- ) { curr = a [ i ] [ j ] ; c = a [ i + 1 ] [ j ] + curr ; d = a [ i + 1 ] [ j + 1 ] + curr ; curr = c >= d ? c : d ; a [ i ] [ j ] = curr ; } } printf ( "%d\n" , a [ 0 ] [ 0 ] ) ; } return 0 ; }
int main ( ) { int i , j , T , N , curr , c , d ; scanf ( "%d" , & T ) ; for ( i = 1 ; i <= T ; i ++ ) { scanf ( "%d" , & N ) ; int a [ N ] [ N ] ; for ( i = 0 ; i < N ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) { scanf ( "%d" , & a [ i ] [ j ] ) ; } } for ( i = N - 2 ; i >= 0 ; i -- ) { for ( j = i ; j >= 0 ; j -- ) { curr = a [ i ] [ j ] ; c = a [ i + 1 ] [ j ] + curr ; d = a [ i + 1 ] [ j + 1 ] + curr ; curr = c >= d ? c : d ; a [ i ] [ j ] = curr ; } } printf ( "%d\n" , a [ 0 ] [ 0 ] ) ; } return 0 ; }
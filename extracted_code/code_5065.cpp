int main ( ) { int a [ 100 ] [ 100 ] , i , j , k , count , sum = 0 , n ; scanf ( "%d" , & count ) ; for ( k = 0 ; k < count ; k ++ ) { scanf ( "%d" , & n ) ; for ( i = 0 ; i < n ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) scanf ( "%d" , & a [ i ] [ j ] ) ; } for ( i = n - 1 ; i > 0 ; i -- ) { for ( j = 0 ; j < i ; j ++ ) { if ( a [ i ] [ j ] < a [ i ] [ j + 1 ] ) { sum = a [ i ] [ j + 1 ] ; } else { sum = a [ i ] [ j ] ; } a [ i - 1 ] [ j ] = a [ i - 1 ] [ j ] + sum ; } } printf ( "%d\n" , a [ 0 ] [ 0 ] ) ; } return 0 ; }
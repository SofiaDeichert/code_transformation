int max ( int a , int b ) { if ( a < b ) return b ; else a ; } void main ( ) { int a [ 100 ] [ 100 ] , result [ 100 ] ; int i = 0 , j = 0 , n , m1 , k = 0 ; scanf ( "%d" , & m1 ) ; for ( k = 0 ; k < m1 ; k ++ ) { scanf ( "%d" , & n ) ; for ( i = 0 ; i < n ; i ++ ) { j = 0 ; while ( j <= i ) { scanf ( "%d" , & a [ i ] [ j ] ) ; j ++ ; } } i = n - 2 ; while ( i >= 0 ) { for ( j = 0 ; j <= i ; j ++ ) { a [ i ] [ j ] = a [ i ] [ j ] + max ( a [ i + 1 ] [ j ] , a [ i + 1 ] [ j + 1 ] ) ; } i -- ; } printf ( "%d\n" , a [ 0 ] [ 0 ] ) ; } }
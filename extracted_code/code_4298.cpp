int maxim ( int a , int b ) { return ( a > b ? a : b ) ; } int main ( ) { int x , i , j , t , n , a [ 100 ] [ 100 ] , s [ 100 ] [ 100 ] ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d" , & n ) ; for ( i = 0 ; i < n ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) { scanf ( "%d" , & a [ i ] [ j ] ) ; } } for ( i = 0 ; i < n ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) { if ( i == 0 && j == 0 ) { s [ i ] [ j ] = a [ i ] [ j ] ; } else if ( i != 0 && j == 0 ) { s [ i ] [ j ] = a [ i ] [ j ] + s [ i - 1 ] [ j ] ; } else { s [ i ] [ j ] = a [ i ] [ j ] + maxim ( s [ i - 1 ] [ j ] , s [ i - 1 ] [ j - 1 ] ) ; } } } i = n - 1 ; x = s [ i ] [ 0 ] ; for ( j = 1 ; j < n ; j ++ ) if ( s [ i ] [ j ] > x ) x = s [ i ] [ j ] ; printf ( "%d\n" , x ) ; } return 0 ; }
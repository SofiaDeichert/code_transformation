int main ( ) { int t ; scanf ( "%d" , & t ) ; while ( t -- ) { int i , j , n , a [ 100 ] [ 100 ] = { 0 } , sum = 0 ; scanf ( "%d" , & n ) ; for ( i = 0 ; i < n ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) { scanf ( "%d" , & a [ i ] [ j ] ) ; } } j = 0 ; for ( i = 0 ; i < n ; i ++ ) { if ( a [ i ] [ j ] > a [ i ] [ j + 1 ] ) sum += a [ i ] [ j ] ; else sum += a [ i ] [ ++ j ] ; } printf ( "%d" , sum ) ; } return 0 ; }
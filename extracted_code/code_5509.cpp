int max ( int a , int b ) { return ( a > b ) ? a : b ; } int main ( ) { int no , n , ans , tm [ 100 ] [ 100 ] = { 0 } , i , j ; scanf ( "%d" , & no ) ; no ++ ; while ( no -- ) { ans = - 1 ; scanf ( "%d" , & n ) ; for ( i = 0 ; i < n ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) { scanf ( "%d" , & tm [ i ] [ j ] ) ; if ( j != 0 && i != 0 ) tm [ i ] [ j ] = tm [ i ] [ j ] + max ( tm [ i - 1 ] [ j ] , tm [ i - 1 ] [ j - 1 ] ) ; if ( j == 0 && i != 0 ) tm [ i ] [ j ] = tm [ i ] [ j ] + tm [ i - 1 ] [ j ] ; if ( i == n - 1 ) { if ( tm [ i ] [ j ] > ans ) ans = tm [ i ] [ j ] ; } } } printf ( "%d\n" , ans ) ; for ( i = 0 ; i < 100 ; i ++ ) { for ( j = 0 ; j < 100 ; j ++ ) tm [ i ] [ j ] = 0 ; } } return 0 ; }
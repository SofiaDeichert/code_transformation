int max ( int a , int b ) { if ( a > b ) return a ; else return b ; } int main ( ) { int t ; scanf ( "%d" , & t ) ; while ( t -- ) { int n , a [ 100 ] [ 100 ] , b [ 100 ] [ 100 ] , i , j ; scanf ( "%d" , & n ) ; int k = 0 ; for ( i = 0 ; i < n ; i ++ ) { for ( j = 0 ; j <= k ; j ++ ) { scanf ( "%d" , & a [ i ] [ j ] ) ; } k ++ ; } k = 0 ; b [ 0 ] [ 0 ] = a [ 0 ] [ 0 ] ; for ( i = 0 ; i < n ; i ++ ) { for ( j = 0 ; j <= k ; j ++ ) { if ( j == 0 && i != 0 ) { b [ i ] [ j ] = a [ i ] [ j ] + b [ i - 1 ] [ j ] ; } else if ( j == i && i != 0 ) b [ i ] [ j ] = a [ i ] [ j ] + b [ i - 1 ] [ j - 1 ] ; else if ( i != 0 ) b [ i ] [ j ] = max ( b [ i - 1 ] [ j ] , b [ i - 1 ] [ j - 1 ] ) + a [ i ] [ j ] ; } k ++ ; } int ans = b [ n - 1 ] [ 0 ] ; for ( i = 1 ; i < n ; i ++ ) { if ( ans < b [ n - 1 ] [ i ] ) ans = b [ n - 1 ] [ i ] ; } printf ( "%d\n" , ans ) ; } return 0 ; }
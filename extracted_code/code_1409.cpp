int n ; int a [ 1000 ] [ 1000 ] ; int b [ 1000 ] [ 1000 ] = { - 1 } ; int solve ( int , int ) ; int main ( ) { int t = 0 ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d" , & n ) ; int i = 0 ; int j = 0 ; for ( i = 0 ; i < 1000 ; i ++ ) { for ( j = 0 ; j < 1000 ; j ++ ) { b [ i ] [ j ] = - 1 ; } } for ( i = 0 ; i < n ; i ++ ) { for ( j = 0 ; j < i + 1 ; j ++ ) { scanf ( "%d" , & a [ i ] [ j ] ) ; } } i = 0 ; j = 0 ; int ans = solve ( i , j ) ; printf ( "%d\n" , ans ) ; } return 0 ; } int solve ( i , j ) { if ( i > n - 1 ) { return 0 ; } if ( b [ i ] [ j ] != - 1 ) { return b [ i ] [ j ] ; } int t1 = solve ( i + 1 , j ) ; int t2 = solve ( i + 1 , j + 1 ) ; int t ; if ( t1 > t2 ) { t = t1 + a [ i ] [ j ] ; } else { t = t2 + a [ i ] [ j ] ; } b [ i ] [ j ] = t ; return t ; }
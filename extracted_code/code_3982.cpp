int dp ( int a [ 100 ] [ 100 ] , int s ) ; int main ( ) { int i , j , k , l , t ; scanf ( "%d" , & t ) ; while ( t -- ) { int s ; scanf ( "%d" , & s ) ; int a [ 100 ] [ 100 ] = { 0 } ; for ( i = 0 ; i < s ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) { scanf ( "%d" , & a [ i ] [ j ] ) ; } } int res = dp ( a , s ) ; printf ( "%d\n" , res ) ; } return 0 ; } int dp ( int a [ 100 ] [ 100 ] , int s ) { int arr [ 100 ] [ 100 ] = { 0 } , i , j ; arr [ 0 ] [ 0 ] = a [ 0 ] [ 0 ] ; for ( i = 1 ; i < s ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) { int x = arr [ i - 1 ] [ j ] + a [ i ] [ j ] ; int y = 0 ; if ( j - 1 >= 0 ) y = arr [ i - 1 ] [ j - 1 ] + a [ i ] [ j ] ; if ( x > y ) arr [ i ] [ j ] = x ; else arr [ i ] [ j ] = y ; } } int max = 0 ; for ( i = s - 1 , j = 0 ; j <= i ; j ++ ) { if ( arr [ i ] [ j ] >= max ) max = arr [ i ] [ j ] ; } return max ; }
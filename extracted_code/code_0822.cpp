int ar [ 5050 ] ; int n ; int max ( ) ; int main ( ) { int t ; int i , j ; scanf ( "%d" , & t ) ; for ( ; t > 0 ; t -- ) { scanf ( "%d" , & n ) ; for ( i = 1 ; i <= n ; i ++ ) for ( j = 1 ; j <= i ; j ++ ) scanf ( "%d" , & ar [ ( ( i - 1 ) * i ) / 2 + j - 1 ] ) ; printf ( "%d\n" , max ( ) ) ; } } int max ( ) { int i , j ; int t1 , t2 ; for ( i = n - 1 ; i >= 1 ; i ++ ) { for ( j = 1 ; j <= i ; j ++ ) { t1 = ar [ ( ( i + 1 ) * i ) / 2 + j - 1 ] ; t2 = ar [ ( ( i + 1 ) * i ) / 2 + j ] ; ar [ ( ( i - 1 ) * i ) / 2 + j - 1 ] = t1 > t2 ? t1 : t2 ; } } return ar [ 0 ] ; }
int main ( ) { int t , n , i , j ; printf ( "Enter the test case:\n" ) ; scanf ( "%d" , & t ) ; while ( t > 0 ) { printf ( "Enter the number of lines:\n" ) ; scanf ( "%d" , & n ) ; int A [ n ] [ n ] ; printf ( "Enter the numebrs:\n" ) ; for ( i = 0 ; i < n ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) { scanf ( "%d" , & A [ i ] [ j ] ) ; } } int k ; i = n - 2 ; while ( i >= 0 ) { for ( k = 0 ; k <= i ; k ++ ) { int a , b , c ; a = A [ i ] [ k ] + A [ i + 1 ] [ k ] ; b = A [ i ] [ k ] + A [ i + 1 ] [ k + 1 ] ; c = a - b ; if ( c > 0 ) { A [ i ] [ k ] = a ; } else { A [ i ] [ k ] = b ; } } i -- ; } printf ( "%d\n" , A [ 0 ] [ 0 ] ) ; t -- ; } return 0 ; }
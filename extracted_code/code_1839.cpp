int main ( ) { int t ; scanf ( "%d" , & t ) ; while ( t -- ) { int n , i ; scanf ( "%d" , & n ) ; int a [ n ] ; for ( i = 0 ; i < n ; i ++ ) { scanf ( "%d" , & a [ i ] ) ; } int flag = 1 ; int max = n - 1 ; int x = 0 ; int y = n / 2 ; for ( i = 0 ; i <= y ; i ++ ) { int count = 0 ; while ( ( a [ x ] == i + 1 ) && ( a [ max - x ] == i + 1 ) ) { x ++ ; count ++ ; if ( x > ( max / 2 ) ) break ; } if ( count > 1 ) { i = i + count - 2 ; y = y - count + 1 ; } if ( count == 0 ) { flag = 0 ; break ; } } if ( flag == 1 ) printf ( "yes\n" ) ; else printf ( "no\n" ) ; } return 0 ; }
int main ( ) { int a , b , c , i ; scanf ( "%d" , & a ) ; for ( b = 0 ; b < a ; b ++ ) { scanf ( "%d" , & c ) ; int n [ c ] , sum = 0 ; for ( i = 0 ; i < c ; i ++ ) scanf ( "%d" , & n [ i ] ) ; for ( i = 0 ; i < c - 1 ; i ++ ) { if ( n [ i ] > n [ i + 1 ] ) { sum = sum + n [ i + 1 ] ; } else { sum = sum + n [ i ] ; n [ i + 1 ] = n [ i ] ; } } printf ( "%d\n" , sum ) ; } return 0 ; }
int main ( ) { int nodes [ 4950 ] ; int results [ 1000 ] ; int i , j , k , temp ; char line [ 500 ] ; int testcases ; int maxlevel ; scanf ( "%d" , & testcases ) ; int testcases1 = testcases ; while ( testcases1 > 0 ) { scanf ( "%d" , & maxlevel ) ; getchar ( ) ; j = 0 , temp = 0 ; for ( k = 0 ; k < maxlevel ; k ++ ) { gets ( line ) ; for ( i = 0 ; i < strlen ( line ) + 1 ; i ++ ) { if ( line [ i ] != ' ' && line [ i ] != 0 ) { temp = ( temp * 10 ) + ( line [ i ] - 48 ) ; } else { nodes [ j ] = temp ; temp = 0 ; j ++ ; } } } j = ( ( maxlevel * ( maxlevel - 1 ) ) / 2 ) - 1 ; for ( i = 1 ; i < maxlevel ; i ++ ) { for ( k = 0 ; k < maxlevel - i ; k ++ ) { nodes [ j ] += nodes [ j + maxlevel - i ] >= nodes [ j + maxlevel - i + 1 ] ? nodes [ j + maxlevel - i ] : nodes [ j + maxlevel - i + 1 ] ; j -- ; } } results [ testcases1 ] = nodes [ 0 ] ; testcases1 -- ; } while ( testcases > 0 ) { printf ( "%d\n" , results [ testcases ] ) ; testcases -- ; } return 0 ; }
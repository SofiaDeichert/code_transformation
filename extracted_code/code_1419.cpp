int arr [ 100 ] [ 100 ] , res [ 100 ] [ 100 ] , len ; int foo ( int i , int j ) { int sum1 = 0 , sum2 = 0 , sum = 0 ; if ( i >= len ) { return 0 ; } if ( res [ i ] [ j ] != - 1 ) { return res [ i ] [ j ] ; } sum1 = sum1 + foo ( i + 1 , j ) ; sum2 += foo ( i + 1 , j + 1 ) ; sum = ( sum1 > sum2 ? sum1 + arr [ i ] [ j ] : sum2 + arr [ i ] [ j ] ) ; res [ i ] [ j ] = sum ; return sum ; } int main ( ) { int i , j , tcase ; scanf ( "%d" , & tcase ) ; while ( tcase ) { int sum = 0 ; scanf ( "%d" , & len ) ; for ( i = 0 ; i < 100 ; i ++ ) for ( j = 0 ; j < 100 ; j ++ ) res [ i ] [ j ] = - 1 ; for ( i = 0 ; i < len ; i ++ ) for ( j = 0 ; j <= i ; j ++ ) scanf ( "%d" , & arr [ i ] [ j ] ) ; sum = foo ( 0 , 0 ) ; printf ( "%d\n" , sum ) ; tcase -- ; } }
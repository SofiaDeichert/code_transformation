int main ( ) { int array [ 99 ] [ 99 ] = { 0 } ; char string [ 300 ] ; int numof_testcases = 0 , numof_rows = 0 ; int i = 0 , j = 0 , k = 1 , max = 0 ; int l = 0 , m = 0 , x = 0 ; scanf ( "%d" , & numof_testcases ) ; for ( i = 0 ; i < numof_testcases ; i ++ ) { scanf ( "%d" , & numof_rows ) ; fflush ( stdin ) ; for ( l = 0 ; l < numof_rows ; l ++ ) { gets ( string ) ; for ( k = 1 , m = 0 ; string [ m ] != '\0' ; m ++ ) { if ( string [ m ] != 32 ) { if ( x != 0 ) x = x * 10 + string [ m ] - 48 ; else x = string [ m ] - 48 ; } else { array [ l ] [ k ++ ] = x ; x = 0 ; } } array [ l ] [ k ++ ] = x ; x = 0 ; } for ( j = 1 ; j < numof_rows ; j ++ ) { for ( k = 1 ; k < j + 2 ; k ++ ) array [ j ] [ k ] += array [ j - 1 ] [ k ] > array [ j - 1 ] [ k - 1 ] ? array [ j - 1 ] [ k ] : array [ j - 1 ] [ k - 1 ] ; } for ( -- j , k = 1 ; k < j + 2 ; k ++ ) { if ( max < array [ j ] [ k ] ) { max = array [ j ] [ k ] ; } } printf ( "%d\n" , max ) ; } return 0 ; }
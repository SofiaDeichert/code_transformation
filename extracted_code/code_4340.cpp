int main ( ) { int test ; scanf ( "%d" , & test ) ; while ( test > 0 ) { int i = 0 ; int rows ; scanf ( "%d" , & rows ) ; int triangle [ rows ] [ 100 ] ; for ( i = 0 ; i < rows ; i ++ ) { int j = 1 ; for ( j = 1 ; j < 100 ; j ++ ) { triangle [ i ] [ j ] = 0 ; } } for ( i = 0 ; i < rows ; i ++ ) { int j = 1 ; for ( j = 1 ; j <= i + 1 ; j ++ ) { int num ; scanf ( "%d" , & num ) ; triangle [ i ] [ j ] = num ; } } int sum = 0 , k = rows - 1 ; int index = k + 1 ; int flag = 0 ; while ( k >= 0 ) { int max = triangle [ k ] [ 1 ] ; if ( flag == 0 ) { int l = 1 ; for ( l = 1 ; l <= index ; l ++ ) { if ( triangle [ k ] [ l ] > max ) { max = triangle [ k ] [ l ] ; index = l ; } } flag = 1 ; if ( index == k + 1 ) { index = index - 1 ; } sum = sum + max ; } else { if ( index == 1 ) { sum = sum + triangle [ k ] [ 1 ] ; } else if ( triangle [ k ] [ index - 1 ] > triangle [ k ] [ index ] ) { max = triangle [ k ] [ index - 1 ] ; sum = sum + max ; index = index - 1 ; } else { max = triangle [ k ] [ index ] ; sum = sum + max ; } } k -- ; } printf ( "%d" , sum ) ; test -- ; } return 0 ; }
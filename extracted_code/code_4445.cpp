void printMat ( ) ; int findMax ( ) ; int matrix [ size ] [ size ] ; int result [ size ] [ size ] ; int main ( ) { int testCase ; int lines ; int i , j ; int row , col ; int item ; int down , right ; int max [ 110 ] ; int itr = 0 ; scanf ( "%d" , & testCase ) ; for ( i = 0 ; i < testCase ; i ++ ) { scanf ( "%d" , & lines ) ; for ( row = 0 ; row < lines ; row ++ ) { for ( col = 0 ; col <= row ; col ++ ) { scanf ( "%d" , & matrix [ row ] [ col ] ) ; } } result [ 0 ] [ 0 ] = matrix [ 0 ] [ 0 ] ; for ( row = 0 ; row < lines ; row ++ ) { for ( col = 0 ; col <= row ; col ++ ) { item = matrix [ row ] [ col ] ; down = row + 1 ; right = col + 1 ; if ( result [ row ] [ col ] + matrix [ down ] [ col ] > result [ down ] [ col ] ) result [ down ] [ col ] = result [ row ] [ col ] + matrix [ down ] [ col ] ; if ( result [ row ] [ col ] + matrix [ down ] [ right ] > result [ down ] [ right ] ) result [ down ] [ right ] = result [ row ] [ col ] + matrix [ down ] [ right ] ; } } printf ( "%d\n" , findMax ( ) ) ; for ( row = 0 ; matrix [ row ] [ 0 ] != 0 ; row ++ ) { for ( col = 0 ; col <= row ; col ++ ) { matrix [ row ] [ col ] = 0 ; result [ row ] [ col ] = 0 ; } } } return ( 0 ) ; } void printMat ( ) { int row , col ; for ( row = 0 ; matrix [ row ] [ 0 ] != 0 ; row ++ ) { for ( col = 0 ; col <= row ; col ++ ) { printf ( "%d " , result [ row ] [ col ] ) ; } printf ( "\n" ) ; } } int findMax ( ) { int row , col ; int max = 0 ; for ( row = 0 ; matrix [ row ] [ 0 ] != 0 ; row ++ ) { for ( col = 0 ; col <= row ; col ++ ) { if ( result [ row ] [ col ] > max ) max = result [ row ] [ col ] ; } } return max ; }
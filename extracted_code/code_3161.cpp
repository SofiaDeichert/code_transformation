void main ( ) { int t , size ; int i , j , sum , max ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d" , & size ) ; int tri [ size ] [ size ] ; max = sum = 0 ; for ( i = 0 ; i < size ; i ++ ) for ( j = 0 ; j <= i ; j ++ ) scanf ( "%d" , & tri [ i ] [ j ] ) ; for ( i = 0 ; i < size ; i ++ ) { sum = sum + tri [ i ] [ 0 ] ; } max = sum ; for ( j = 1 ; j < size ; j ++ ) { for ( i = size - 1 ; i >= j ; i -- ) { sum = sum + tri [ i ] [ j ] - tri [ i ] [ j - 1 ] ; if ( sum > max ) max = sum ; } } printf ( "%d\n" , max ) ; } }
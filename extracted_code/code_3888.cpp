int main ( void ) { int num , n , rows , j , i , count ; scanf ( "%d" , & n ) ; while ( n ) { scanf ( "%d" , & rows ) ; int array [ rows ] [ rows ] ; for ( j = 0 ; j < rows ; j ++ ) { for ( i = 0 ; i <= j ; i ++ ) { scanf ( "%d" , & array [ j ] [ i ] ) ; } } count = array [ 0 ] [ 0 ] ; i = 0 ; for ( j = 0 ; j < rows - 1 ; j ++ ) { if ( array [ j + 1 ] [ i ] > array [ j + 1 ] [ i + 1 ] ) { num = array [ j + 1 ] [ i ] ; } else { num = array [ j + 1 ] [ i + 1 ] ; i = i + 1 ; } count = count + num ; } printf ( "%d\n" , count ) ; n = n - 1 ; } }
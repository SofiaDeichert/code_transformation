int main ( ) { int a [ MAX_SUPPORTED_ROWS ] [ MAX_SUPPORTED_ROWS ] = { 0 } ; int row_count = 0 ; int i = 0 , j = 0 ; int count ; scanf ( "%d" , & count ) ; while ( count -- > 0 ) { scanf ( "%d" , & row_count ) ; for ( i = 0 ; i < row_count ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) { scanf ( "%d" , & a [ i ] [ j ] ) ; } } } }
int cost [ MAX ] [ MAX ] ; int dp [ MAX ] [ MAX ] ; int results [ MAX ] ; int main ( void ) { int i , j ; int n , numOfLines ; int max , count = 0 ; scanf ( "%d" , & n ) ; while ( n > count ) { scanf ( "%d" , & numOfLines ) ; for ( i = 0 ; i < numOfLines ; i ++ ) for ( j = 0 ; j <= i ; j ++ ) cost [ i ] [ j ] = 0 ; for ( i = 0 ; i < numOfLines ; i ++ ) for ( j = 0 ; j <= i ; j ++ ) scanf ( "%d" , & cost [ i ] [ j ] ) ; for ( i = 0 ; i < numOfLines ; i ++ ) for ( j = 0 ; j <= i ; j ++ ) dp [ i ] [ j ] = 0 ; for ( i = 1 ; i < numOfLines ; i ++ ) { for ( j = 0 ; j < i ; j ++ ) { if ( ( dp [ i - 1 ] [ j ] + cost [ i ] [ j ] ) > dp [ i ] [ j ] ) dp [ i ] [ j ] = dp [ i - 1 ] [ j ] + cost [ i ] [ j ] ; if ( ( dp [ i - 1 ] [ j ] + cost [ i ] [ j + 1 ] ) > dp [ i ] [ j + 1 ] ) dp [ i ] [ j + 1 ] = dp [ i - 1 ] [ j ] + cost [ i ] [ j + 1 ] ; } } max = 0 ; for ( i = 1 ; i < numOfLines ; i ++ ) if ( dp [ numOfLines - 1 ] [ i ] > dp [ numOfLines - 1 ] [ max ] ) max = i ; results [ count ] = dp [ numOfLines - 1 ] [ max ] ; count ++ ; } for ( i = 0 ; i < n ; i ++ ) printf ( "%d\n" , results [ i ] ) ; return 0 ; }
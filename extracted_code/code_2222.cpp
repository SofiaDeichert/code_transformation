struct node { int triangle [ 100 ] [ 100 ] ; int max ; } ; typedef struct node * NODE ; NODE getnode ( void ) { NODE x ; x = malloc ( sizeof ( struct node ) ) ; x -> max = 0 ; return ( x ) ; } int main ( void ) { int count ; int testcases ; int sum = 0 ; NODE cur , temp ; int rows ; int i , j , k ; int num = 0 ; scanf ( "%d" , & testcases ) ; for ( k = 0 ; k < testcases ; k ++ ) { cur = getnode ( ) ; scanf ( "%d" , & rows ) ; if ( rows <= 0 || rows > 100 ) exit ( 0 ) ; for ( i = 1 ; i <= rows ; i ++ ) for ( j = 0 ; j < i ; j ++ ) { scanf ( "%d" , & cur -> triangle [ i - 1 ] [ j ] ) ; if ( cur -> triangle [ i - 1 ] [ j ] < 0 || cur -> triangle [ i - 1 ] [ j ] > 99 ) exit ( 0 ) ; } for ( count = 0 ; count < rows ; count ++ ) { i = rows - 1 ; j = count ; sum = 0 ; while ( i >= 0 ) { if ( j == 0 ) while ( i >= 0 ) sum += cur -> triangle [ i -- ] [ j ] ; else if ( j == i ) while ( i >= 0 ) sum += cur -> triangle [ i -- ] [ j -- ] ; else { sum += cur -> triangle [ i ] [ j ] ; num = ( cur -> triangle [ i - 1 ] [ j ] < cur -> triangle [ i - 1 ] [ j - 1 ] ) ? 1 : 0 ; i -- ; j -= num ; } } if ( sum > cur -> max ) cur -> max = sum ; } printf ( "%d\n" , cur -> max ) ; free ( cur ) ; cur = NULL ; } return 0 ; }
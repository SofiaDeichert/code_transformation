int main ( ) { int n ; scanf ( "%d" , & n ) ; int a [ n ] , b [ n ] , i , r ; double l ; i = n ; while ( i -- ) { scanf ( "%d %d" , & a [ i ] , & b [ i ] ) ; l = a [ i ] * b [ i ] ; do { r = a [ i ] % b [ i ] ; a [ i ] = b [ i ] ; b [ i ] = r ; } while ( r != 0 ) ; b [ i ] = l / a [ i ] ; } for ( i = n - 1 ; i >= 0 ; i -- ) { printf ( "%d %d\n" , a [ i ] , b [ i ] ) ; } }
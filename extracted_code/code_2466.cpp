int max ( int a , int b ) { return a > b ? a : b ; } int main ( ) { int t , n , i , j , temp , m ; int * a ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d" , & n ) ; a = ( int * ) calloc ( n + 1 , sizeof ( int ) ) ; for ( i = 0 ; i < n ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) { scanf ( "%d" , & temp ) ; a [ n - 1 - i + j ] = temp + max ( a [ n - 1 - i + j ] , a [ n - i + j ] ) ; } } m = a [ 0 ] ; for ( i = 0 ; i < n ; i ++ ) if ( m < a [ i ] ) m = a [ i ] ; printf ( "%d\n" , m ) ; free ( a ) ; } return 0 ; }
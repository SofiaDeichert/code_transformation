int findd ( int , int ) ; int arr [ 100 ] [ 100 ] , n ; int main ( ) { int t ; scanf ( "%d" , & t ) ; while ( t -- ) { int i , j , res ; scanf ( "%d" , & n ) ; for ( i = 0 ; i < n ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) { scanf ( "%d" , & arr [ i ] [ j ] ) ; } } res = findd ( 0 , 0 ) ; printf ( "%d" , res ) ; printf ( "\n" ) ; } getchar ( ) ; return 0 ; } int findd ( int i , int j ) { int t1 , t2 , t ; if ( i > n ) { return 0 ; } t1 = findd ( i + 1 , j ) ; t2 = findd ( i + 1 , j + 1 ) ; t = arr [ i ] [ j ] + ( t1 > t2 ? t1 : t2 ) ; return t ; }
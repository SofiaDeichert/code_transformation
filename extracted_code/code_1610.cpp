int fun1 ( ) { int i , j , size ; int * * array ; int result = 0 ; scanf ( "%d" , & size ) ; array = ( int * * ) malloc ( size * sizeof ( int * ) ) ; for ( i = 0 ; i < size ; i ++ ) { array [ i ] = ( int * ) malloc ( size * sizeof ( int ) ) ; } for ( i = 0 ; i < size ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) scanf ( "%d " , & array [ i ] [ j ] ) ; } result = ( array [ 0 ] [ 0 ] + fun2 ( array , 1 , 0 , size ) ) ; return result ; } int fun2 ( int * * temp , int i , int j , int size ) { int x , y ; if ( i < size ) { x = ( temp [ i ] [ j ] + ( fun2 ( temp , i + 1 , j , size ) ) ) ; y = ( temp [ i ] [ j + 1 ] + fun2 ( temp , i + 1 , j + 1 , size ) ) ; } else return 0 ; if ( x > y ) return x ; else return y ; } int main ( ) { int test , result ; scanf ( "%d" , & test ) ; while ( test ) { result = fun1 ( ) ; printf ( "%d\n" , result ) ; test -- ; } return 0 ; }
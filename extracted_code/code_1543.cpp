int rpn ( int * , int , int , int * ) ; int maxj = 0 , maxk = 0 ; int main ( ) { int i = - 1 , count = 0 , j_count , j = - 1 , k = - 1 ; scanf ( "%d" , & count ) ; while ( ++ i < count ) { int k = 0 , l = 0 ; int arr [ 100 ] [ 100 ] , cache [ 100 ] [ 100 ] ; j = - 1 ; scanf ( "%d" , & j_count ) ; while ( ++ j < j_count ) { int k = - 1 ; while ( ++ k <= j ) scanf ( "%d" , & arr [ j ] [ k ] ) ; } maxj = j ; maxk = k ; printf ( "%d\n" , rpn ( & arr [ 0 ] [ 0 ] , 0 , 0 , & cache [ 0 ] [ 0 ] ) ) ; } return 0 ; } int max ( int a , int b ) { if ( a > b ) return a ; return b ; } int rpn ( int * arr , int j , int k , int * cache ) { { if ( ( j >= maxj ) || ( k > maxj ) ) return 0 ; if ( cache [ j * 100 + k ] != 0 ) return cache [ j * 100 + k ] ; cache [ j * 100 + k ] = arr [ j * 100 + k ] + max ( rpn ( arr , j + 1 , k , cache ) , rpn ( arr , j + 1 , k + 1 , cache ) ) ; return arr [ j * 100 + k ] + max ( rpn ( arr , j + 1 , k , cache ) , rpn ( arr , j + 1 , k + 1 , cache ) ) ; } }
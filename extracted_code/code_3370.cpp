int tri [ 100 ] [ 100 ] ; int cache [ 100 ] [ 100 ] = { 0 } ; int sum_triangle ( int , int , int , int [ 100 ] [ 100 ] ) ; int max ( int x , int y ) { if ( x > y ) return x ; else return y ; } int main ( ) { int t , i , j , n , k ; scanf ( "%d" , & t ) ; int sum [ t ] ; for ( i = 0 ; i < t ; i ++ ) { memset ( cache , 0 , sizeof ( cache ) ) ; scanf ( "%d" , & n ) ; for ( j = 0 ; j < n ; j ++ ) for ( k = 0 ; k <= j ; k ++ ) scanf ( "%d" , & tri [ j ] [ k ] ) ; sum [ i ] = sum_triangle ( 0 , 0 , n , tri ) ; } for ( i = 0 ; i < t ; i ++ ) printf ( "%d\n" , sum [ i ] ) ; return 0 ; } int sum_triangle ( int x , int y , int n , int tri [ 100 ] [ 100 ] ) { if ( x > n ) return 0 ; else { if ( cache [ x ] [ y ] ) return cache [ x ] [ y ] ; else { cache [ x ] [ y ] = max ( sum_triangle ( x + 1 , y , n , tri ) , sum_triangle ( x + 1 , y + 1 , n , tri ) ) + tri [ x ] [ y ] ; return cache [ x ] [ y ] ; } } }
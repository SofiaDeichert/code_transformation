int sum ( int , int ) ; int m = 0 , b [ 100 ] [ 100 ] , ch = 0 ; int main ( ) { int n , i , a [ 1000 ] , j , k ; scanf ( "%d" , & n ) ; for ( i = 0 ; i < n ; i ++ ) { scanf ( "%d" , & m ) ; for ( j = 0 ; j < m ; j ++ ) for ( k = 0 ; k <= j ; k ++ ) scanf ( "%d" , & b [ j ] [ k ] ) ; a [ i ] = sum ( 0 , 0 ) ; } for ( i = 0 ; i < n ; i ++ ) printf ( "%d\n" , a [ i ] ) ; return 0 ; } int sum ( int i , int j ) { int n , n1 , n2 , q ; if ( i >= m ) return 0 ; if ( b [ i ] [ j ] == 0 ) return ch ; n1 = sum ( i + 1 , j ) ; n2 = sum ( i + 1 , j + 1 ) ; if ( n1 > n2 ) q = n1 ; else q = n2 ; n = q + b [ i ] [ j ] ; b [ i ] [ j ] = 0 ; ch = n ; return n ; }
int a [ 100 ] [ 100 ] ; int sum ( int a [ 100 ] [ 100 ] , int n , int i , int j ) { int x , y ; if ( ( i + 1 ) == n ) return a [ i ] [ j ] ; else { x = a [ i ] [ j ] + sum ( a , n , i + 1 , j ) ; y = a [ i ] [ j ] + sum ( a , n , i + 1 , j + 1 ) ; } return ( x > y ? x : y ) ; } void main ( ) { int t , n , i , j ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d" , & n ) ; for ( i = 0 ; i < n ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) { scanf ( "%d" , & a [ i ] [ j ] ) ; } } printf ( "%d\n" , sum ( a , n , 0 , 0 ) ) ; } }
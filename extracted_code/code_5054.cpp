int max ( int ele1 , int ele2 ) { if ( ele1 > ele2 ) return ele1 ; else return ele2 ; } int main ( ) { int i , nor , not , a [ 100 ] [ 100 ] , sum , n , j ; scanf ( "%d" , & not ) ; for ( n = 0 ; n < not ; n ++ ) { scanf ( "%d" , & nor ) ; sum = 0 ; for ( i = 1 ; i <= nor ; i ++ ) sum = sum + i ; for ( i = 0 ; i < sum ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) { scanf ( "%d" , & a [ i ] [ j ] ) ; } } for ( i = nor - 2 ; i >= 0 ; i -- ) { for ( j = i ; j >= 0 ; j -- ) { a [ i ] [ j ] = a [ i ] [ j ] + max ( a [ i + 1 ] [ j ] , a [ i + 1 ] [ j + 1 ] ) ; } } } }
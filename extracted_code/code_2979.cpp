int a [ SIZE ] [ SIZE ] ; int funmax ( int a , int b ) { if ( a > b ) return a ; else return b ; } int calculate_max_sum ( int i , int j , int n ) { int sum = 0 ; if ( i < n && j < n ) { sum = sum + a [ i ] [ j ] ; sum = sum + funmax ( calculate_max_sum ( i + 1 , j , n ) , calculate_max_sum ( i + 1 , j + 1 , n ) ) ; } return sum ; } int main ( ) { int t , i , j , n , sum ; scanf ( "%d" , & t ) ; for ( int k = 0 ; k < t ; k ++ ) { scanf ( "%d" , & n ) ; for ( i = 0 ; i < n ; i ++ ) for ( j = 0 ; j <= i ; j ++ ) scanf ( "%d" , & a [ i ] [ j ] ) ; sum = a [ 0 ] [ 0 ] + funmax ( calculate_max_sum ( 1 , 0 , n ) , calculate_max_sum ( 1 , 1 , n ) ) ; printf ( "%d\n" , sum ) ; } return 0 ; }
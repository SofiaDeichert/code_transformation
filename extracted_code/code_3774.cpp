int sun ( int , int , int ) ; int arr [ 200 ] [ 200 ] ; int main ( ) { int t , n , i , j , k , val ; scanf ( "%d" , & t ) ; for ( i = 0 ; i < t ; i ++ ) { scanf ( "%d" , & n ) ; for ( j = 0 ; j < n ; j ++ ) { for ( k = 0 ; k <= j ; k ++ ) scanf ( "%d" , & arr [ j ] [ k ] ) ; } printf ( "%d\n" , sum ( 0 , 0 , n ) ) ; } return ( 0 ) ; } int sum ( int j , int k , int n ) { int s1 , s2 ; if ( j == n - 1 ) return ( arr [ j ] [ k ] ) ; else { s1 = arr [ j ] [ k ] + sum ( j + 1 , k , n ) ; s2 = arr [ j ] [ k ] + sum ( j + 1 , k + 1 , n ) ; return ( s1 > s2 ? s1 : s2 ) ; } }
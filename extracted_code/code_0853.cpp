void triangle_sum ( int , int , int ) ; int arr [ 1000 ] [ 1000 ] , max , n ; int main ( ) { int test , i , j ; scanf ( "%d" , & test ) ; while ( test > 0 ) { max = 0 ; scanf ( "%d" , & n ) ; for ( i = 0 ; i < n ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) { scanf ( "%d" , & arr [ i ] [ j ] ) ; } } triangle_sum ( 0 , 0 , 0 ) ; printf ( "%d\n" , max ) ; test -- ; } return 0 ; } void triangle_sum ( int sum , int i , int j ) { if ( i <= n - 1 && j <= n - 1 ) { sum = sum + arr [ i ] [ j ] ; if ( sum > max ) { max = sum ; } triangle_sum ( sum , i + 1 , j ) ; triangle_sum ( sum , i + 1 , j + 1 ) ; } return ; }
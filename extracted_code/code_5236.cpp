int main ( ) { int num_cases , n , triangle [ 100 ] [ 100 ] , i , j , temp , idx = 0 , copy ; scanf ( "%d" , & num_cases ) ; int answers [ num_cases ] ; copy = num_cases ; while ( copy -- > 0 ) { scanf ( "%d" , & n ) ; for ( i = 0 ; i < n ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) { scanf ( "%d" , & triangle [ i ] [ j ] ) ; } } for ( i = n - 2 ; i >= 0 ; i -- ) { for ( j = 0 ; j <= i ; j ++ ) { temp = triangle [ i ] [ j ] + triangle [ i + 1 ] [ j ] ; if ( temp < triangle [ i ] [ j ] + triangle [ i + 1 ] [ j + 1 ] ) temp = triangle [ i ] [ j ] + triangle [ i + 1 ] [ j + 1 ] ; triangle [ i ] [ j ] = temp ; } } answers [ idx ++ ] = triangle [ 0 ] [ 0 ] ; } for ( i = 0 ; i < num_cases ; i ++ ) { printf ( "%d\n" , answers [ i ] ) ; } }
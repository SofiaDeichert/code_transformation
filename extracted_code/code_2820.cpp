int read_int ( ) { char c = gc ( ) ; while ( c < '0' || c > '9' ) c = gc ( ) ; int ret = 0 ; while ( c >= '0' && c <= '9' ) { ret = 10 * ret + c - 48 ; c = gc ( ) ; } return ret ; } int main ( ) { int test , i , n , j , temp , temp2 , value , max ; test = read_int ( ) ; while ( test -- ) { max = - 1 ; int arr [ 100 ] = { 0 } ; scanf ( "%d" , & n ) ; for ( i = 1 ; i <= n ; i ++ ) { temp = 0 ; temp2 = 0 ; for ( j = 1 ; j <= i ; j ++ ) { value = read_int ( ) ; temp = arr [ j ] ; arr [ j ] = ( ( arr [ j ] > temp2 ) ? arr [ j ] : temp2 ) + value ; temp2 = temp ; if ( i == n && arr [ j ] > max ) { max = arr [ j ] ; } } } printf ( "%d\n" , max ) ; } return 0 ; }
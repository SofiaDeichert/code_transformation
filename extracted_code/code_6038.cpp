int main ( ) { int a , b , n , t , g , i , j , l ; scanf ( "%d" , & t ) ; for ( i = 1 ; i <= t ; i ++ ) { scanf ( "%d%d" , & a , & b ) ; if ( a < b ) n = a ; else n = b ; for ( j = 1 ; j <= n ; j ++ ) { if ( a % j == 0 && b % j == 0 ) g = j ; } l = a * b / g ; printf ( "%d %d\n" , g , l ) ; } }
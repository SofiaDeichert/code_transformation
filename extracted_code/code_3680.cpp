int main ( ) { int a , b , H , L , n ; scanf ( "%d" , & n ) ; while ( n -- ) ; { scanf ( "%d%d" , & a , & b ) ; for ( H = a < b ? a : b ; H >= 1 ; H -- ) if ( b % H == 0 && a % H == 0 ) break ; printf ( "%d " , H ) ; for ( L = a > b ? a : b ; L <= a * b ; L ++ ) if ( L % a == 0 && L % b == 0 ) break ; printf ( "%d\n" , L ) ; } return 0 ; }
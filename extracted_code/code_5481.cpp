int main ( ) { int t , b , i = 0 ; float g , h , d ; scanf ( "%d" , & t ) ; for ( i = 0 ; i < t ; i ++ ) { scanf ( "%d" , & b ) ; if ( b > 1500 ) { h = 500 ; d = 0.98 * b ; } else { h = 0.1 * b ; d = 0.9 * b ; } g = ( float ) b + h + d ; printf ( "%g\n" , g ) ; } return 0 ; }
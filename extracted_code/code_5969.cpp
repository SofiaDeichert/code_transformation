int gcd ( int x , int y ) { int a ; a = y % x ; if ( a == 0 ) return x ; gcd ( a , x ) ; } int main ( ) { int a , b , swap , c , d , t , i ; scanf ( "%d" , & t ) ; for ( i = 1 ; i <= t ; i ++ ) { scanf ( "%d%d" , & a , & b ) ; if ( a > b ) { swap = a ; a = b ; b = swap ; } if ( b % a == 0 ) { d = ( a * b ) / a ; printf ( "%d %d\n" , a , d ) ; } else { c = gcd ( a , b ) ; d = ( a * b ) / c ; printf ( "%d %d\n" , c , d ) ; } } return 0 ; }
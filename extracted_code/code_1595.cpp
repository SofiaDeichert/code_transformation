int main ( ) { int i , j , t , a , b , gcd = 1 , temp ; scanf ( "%d" , & t ) ; for ( i = 0 ; i < t ; i ++ ) { scanf ( "%d %d" , & a , & b ) ; if ( b > a ) { temp = a ; a = b ; b = temp ; } for ( j = 2 ; j <= b ; j ++ ) { if ( a % j == 0 && b % j == 0 ) gcd = j ; } printf ( "%d %ld\n" , gcd , a * b / gcd ) ; } return 0 ; }
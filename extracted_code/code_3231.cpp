int main ( ) { int i , temp , T , j , k ; scanf ( "%d" , & T ) ; int a , b , lcm , gcd ; for ( j = 0 ; j < T ; j ++ ) { scanf ( "%d %d" , & a , & b ) ; if ( a > b ) { temp = a ; a = b ; b = temp ; } gcd = 1 ; for ( i = 2 ; i <= a ; i ++ ) { if ( a % i == 0 && b % i == 0 ) { gcd = i ; } } lcm = a * b / gcd ; printf ( "%d %d\n" , gcd , lcm ) ; i = 2 ; gcd = 1 ; } return 0 ; }
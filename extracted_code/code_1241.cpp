int main ( ) { int T , i , z ; scanf ( "%d" , & T ) ; int a [ T ] , b [ T ] ; for ( i = 0 ; i < T ; i ++ ) scanf ( "%d%d" , & a [ i ] , & b [ i ] ) ; for ( i = 0 ; i < T ; i ++ ) { z = gcd ( a [ i ] , b [ i ] ) ; printf ( "%d %d\n" , z , ( a [ i ] * b [ i ] / z ) ) ; } } int gcd ( int a , int b ) { int temp , rem ; if ( a > b ) { temp = a ; a = b ; b = temp ; } rem = b % a ; if ( rem == 0 ) return ( a ) ; else { b = a ; a = rem ; return ( gcd ( a , b ) ) ; } }
int GCD ( int , int ) ; int main ( ) { int i , T , p ; int num1 [ 1000 ] , num2 [ 1000 ] ; scanf ( "%d" , & T ) ; for ( i = 0 ; i < T ; i ++ ) scanf ( "%d%d" , & num1 [ i ] , & num2 [ i ] ) ; for ( i = 0 ; i < T ; i ++ ) { p = GCD ( num1 [ i ] , num2 [ i ] ) ; printf ( "%d %d\n" , p , ( num1 [ i ] * num2 [ i ] ) / p ) ; } return 0 ; } int GCD ( int a , int b ) { int i , smaller , max = 1 ; if ( a >= b ) smaller = b ; else smaller = a ; for ( i = 2 ; i <= smaller ; i ++ ) if ( ( a % i == 0 ) && ( b % i == 0 ) ) max = i ; return max ; }
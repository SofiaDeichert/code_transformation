int main ( ) { int n1 , n2 , prod , gcd , lcm , t ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d %d" , & n1 , & n2 ) ; prod = n1 * n2 ; while ( n1 != n2 ) { if ( n1 > n2 ) n1 = n1 - n2 ; if ( n2 > n1 ) n2 = n2 - n1 ; } gcd = n1 ; lcm = prod / gcd ; } printf ( "\nThe GCD is : %d" , gcd ) ; printf ( "\n\nThe LCM is : %d" , lcm ) ; return 0 ; }
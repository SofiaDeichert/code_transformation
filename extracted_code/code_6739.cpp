int GCD ( int n1 , int n2 ) { while ( n1 != n2 ) { if ( n1 == 0 || n2 == 0 ) return 0 ; if ( n1 > n2 ) n1 = n1 - n2 ; if ( n1 < n2 ) n2 = n2 - n1 ; } return n1 ; } int main ( ) { int gcd , lcm , t , n1 , n2 ; scanf ( "%d" , & t ) ; while ( t > 0 ) { scanf ( "%d" , & n1 ) ; scanf ( "%d" , & n2 ) ; gcd = GCD ( n1 , n2 ) ; lcm = n1 * n2 / gcd ; printf ( "%d" , gcd ) ; printf ( " %d\n" , lcm ) ; t -- ; } return 0 ; }
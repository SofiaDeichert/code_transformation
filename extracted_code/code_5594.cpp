int main ( ) { int n1 , n2 , max , lcm , i ; scanf ( "%d" , & n1 ) ; scanf ( "%d" , & n2 ) ; max = ( n1 > n2 ) ? n1 : n2 ; i = max ; for ( ; ; ) { if ( i % n1 == 0 && i % n2 == 0 ) { lcm = i ; break ; i = i + max ; } printf ( "%d" , lcm ) ; } return 0 ; }
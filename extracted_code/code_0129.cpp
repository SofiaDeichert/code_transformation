int main ( ) { int t ; scanf ( "%d" , & t ) ; while ( t -- ) { int a , b , ans , ans1 ; scanf ( "%d %d\n" , & a , & b ) ; if ( a > b ) { ans = a % b ; if ( ans == 0 ) { printf ( "%d %d\n" , ans , a ) ; } else printf ( "1 %d\n" , a * b ) ; } else { ans = b % a ; if ( ans == 0 ) printf ( "%d %d\n" , ans , b ) ; else printf ( "1 %d\n" , a * b ) ; } } return 0 ; }
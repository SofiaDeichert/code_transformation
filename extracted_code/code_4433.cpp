int hff ( int , int ) ; int main ( ) { int t ; long int a , b , hcf , lcf ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%ld %ld" , & a , & b ) ; hcf = hff ( a , b ) ; printf ( "%ld %ld\n" , hcf , ( a * b / hcf ) ) ; } return 0 ; } hff ( int a , int b ) { if ( b == 0 ) return a ; else return hff ( b , a % b ) ; }
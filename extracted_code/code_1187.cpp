int HCF ( int x , int y ) { if ( x == 0 ) return y ; else return HCF ( y % x , x ) ; } int main ( void ) { int hf , lm ; int t ; int a , b ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d%d" , & a , & b ) ; hf = HCF ( a , b ) ; printf ( "%d %d\n" , hf , a * b / hf ) ; } return 0 ; }
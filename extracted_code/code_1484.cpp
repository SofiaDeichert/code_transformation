int main ( ) { int T ; scanf ( "%d" , & T ) ; while ( T -- ) { int A , B , H , L ; scanf ( "%d%d" , & A , & B ) ; { for ( H = A < B ? A : B ; H >= 1 ; H -- ) if ( A % H == 0 && B % H == 0 ) break ; } { for ( L = A > B ? A : B ; L >= 1 ; L ++ ) if ( L % A == 0 && L % B == 0 ) break ; } printf ( "--" , H , L ) ; } return 0 ; }
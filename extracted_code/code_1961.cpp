int main ( ) { int T , i , A , B , Q , R , j , k , product , LCM ; scanf ( "%d" , & T ) ; if ( T >= 1 && T <= 1000 ) { for ( i = 0 ; i < T ; i ++ ) { scanf ( "%d %d" , & A , & B ) ; if ( A >= 1 && A <= 1000000 && B >= 1 && B <= 1000000 ) { if ( A > B ) { product = A * B ; for ( j = 0 ; ; j ++ ) { Q = A / B ; R = A % B ; if ( R == 0 ) { break ; } A = B ; B = R ; } LCM = product / B ; printf ( "%d %d\n" , B , LCM ) ; } else if ( B > A ) { product = A * B ; for ( k = 0 ; ; k ++ ) { Q = B / A ; R = B % A ; if ( R == 0 ) { break ; } B = A ; A = R ; } LCM = product / A ; printf ( "%d %d\n" , A , LCM ) ; } } } } return 0 ; }
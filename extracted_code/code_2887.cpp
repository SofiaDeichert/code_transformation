void main ( ) { int i , j , tc , a , b , l , h ; scanf ( "%d" , & tc ) ; for ( j = 0 ; j < tc ; j ++ ) { scanf ( "%d %d" , & a , & b ) ; if ( a < b ) { l = a ; h = b ; } else { l = b ; h = a ; } for ( i = l ; i >= 1 ; i -- ) { if ( l % i == 0 && h % i == 0 ) break ; } printf ( "%d " , i ) ; for ( i = h ; i <= l * h ; i ++ ) { if ( i % l == 0 && i % h == 0 ) break ; } printf ( "%d" , i ) ; printf ( "\n" ) ; } }
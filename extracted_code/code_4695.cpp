int a [ 101 ] [ 101 ] , line ; int max ( int * i , int * j ) ; int main ( ) { int cas , i , j , k , * ptr , val ; scanf ( "%d" , & cas ) ; for ( i = 0 ; i < cas ; i ++ ) { scanf ( "%d" , & line ) ; for ( j = 0 ; j < line ; j ++ ) { for ( k = 0 ; k <= j ; k ++ ) { scanf ( "%d" , & a [ j ] [ k ] ) ; } } for ( j = line ; j > 0 ; j -- ) { a [ 0 ] [ j - 1 ] += a [ 0 ] [ j ] ; a [ j - 1 ] [ j - 1 ] += a [ j ] [ j ] ; } for ( k = 1 , j = line ; k < line - 1 , j > 0 ; k ++ , j -- ) { a [ k - 1 ] [ j - 1 ] += a [ k ] [ j ] ; a [ k ] [ j - 1 ] += a [ k ] [ j ] ; } a [ 0 ] [ 0 ] -= ( a [ 1 ] [ 0 ] + a [ 1 ] [ 1 ] ) ; ptr = & a [ 0 ] [ 0 ] ; for ( j = 0 , k = 0 ; j < line , k < line ; j ++ , k ++ ) { * ptr += max ( & a [ j + 1 ] [ k ] , & a [ j + 1 ] [ k + 1 ] ) ; } val = * ptr ; printf ( "%d" , val ) ; } return 0 ; } int max ( int * i , int * j ) { if ( * i >= * j ) { * i -= ( * ( i + line ) + * ( i + line + 1 ) ) ; return * i ; } else if ( * j > * i ) { j -= ( * ( j + line ) + * ( i + line + 1 ) ) ; return * j ; } }
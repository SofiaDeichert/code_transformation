int main ( ) { char s [ 100 ] ; int top = 0 , t , j , k , l = 0 ; scanf ( "%d" , & t ) ; char e [ 400 ] , * e1 [ 4000 ] ; while ( t -- ) { scanf ( "%s" , e ) ; j = k = 0 ; while ( e [ j ] != '\0' ) { if ( e [ j ] == '+' || e [ j ] == '-' || e [ j ] == '*' || e [ j ] == '/' || e [ j ] == '^' ) { s [ k ++ ] = e [ j ] ; } else if ( e [ j ] == ')' ) { e1 [ l ++ ] = s [ -- k ] ; } else if ( e [ j ] != '(' ) { e1 [ l ++ ] = e [ j ] ; } j ++ ; } e1 [ l ++ ] = '\n' ; } e [ l ] = '\0' ; j = 0 ; while ( e1 [ j ] != '\0' ) { printf ( "%c" , e1 [ j ++ ] ) ; } return 0 ; }
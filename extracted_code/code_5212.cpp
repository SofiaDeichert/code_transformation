struct array { int row ; int col ; struct array * next , * prev ; } ; int n , i ; int j , cost [ 100 ] [ 100 ] , n1 , o = 0 , f = 0 , dist [ 100 ] [ 100 ] ; struct array * head = NULL , * temp ; void main ( ) { scanf ( "%d" , & n ) ; while ( o < n ) { int h , n2 = 0 , t = 0 ; scanf ( "%d" , & n1 ) ; while ( n2 < n1 ) { for ( i = 0 ; i <= n2 ; i ++ ) { scanf ( "%d" , & cost [ n2 ] [ i ] ) ; dist [ n2 ] [ i ] = cost [ n2 ] [ i ] ; if ( head == NULL ) { head = ( struct array * ) malloc ( sizeof ( struct array ) ) ; head -> row = ( ( ( n2 ) * n1 ) + i ) ; head -> col = ( ( ( n2 + 1 ) * n1 ) + i ) ; head -> next = NULL ; head -> prev = NULL ; } else { temp = ( struct array * ) malloc ( sizeof ( struct array ) ) ; temp -> row = ( ( ( n2 ) * n1 ) + i ) ; temp -> col = ( ( ( n2 + 1 ) * n1 ) + i ) ; temp -> next = head ; head -> prev = temp ; head = temp ; } temp = ( struct array * ) malloc ( sizeof ( struct array ) ) ; temp -> row = ( ( ( n2 ) * n1 ) + i ) ; temp -> col = ( ( ( n2 + 1 ) * n1 ) + i + 1 ) ; temp -> next = head ; head -> prev = temp ; head = temp ; } n2 ++ ; t ++ ; } h = func ( t ) ; printf ( "%d" , h ) ; o ++ ; } } int func ( int t ) { while ( temp -> next != NULL ) { temp = temp -> next ; } while ( temp -> row != ( ( n1 * n1 ) - n1 ) ) { if ( ( ( temp -> row ) ) % n1 == 0 && f % 2 == 0 ) { for ( j = 0 ; j < n1 ; j ++ ) { cost [ ( ( temp -> row ) / n1 ) ] [ j ] = dist [ ( ( temp -> row ) / n1 ) ] [ j ] ; } } if ( ( ( temp -> row ) ) % n1 == 0 ) f ++ ; if ( dist [ ( temp -> col ) / n1 ] [ ( temp -> col ) % n1 ] < cost [ ( temp -> col ) / n1 ] [ ( temp -> col ) % n1 ] + cost [ ( temp -> row ) / n1 ] [ ( temp -> row ) % n1 ] ) dist [ ( temp -> col ) / n1 ] [ ( temp -> col ) % n1 ] = cost [ ( temp -> col ) / n1 ] [ ( temp -> col ) % n1 ] + cost [ ( temp -> row ) / n1 ] [ ( temp -> row ) % n1 ] ; temp = temp -> prev ; } int max1 = - 9999 ; for ( i = ( ( n1 * n1 ) - n1 ) ; i < ( n1 * n1 ) ; i ++ ) { if ( dist [ i / n1 ] [ i % n1 ] > max1 ) max1 = dist [ i / n1 ] [ i % n1 ] ; } return max1 ; }
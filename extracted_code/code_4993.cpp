struct node { int triangle [ 100 ] [ 100 ] ; int max ; struct node * next ; } ; typedef struct node * NODE ; NODE getnode ( void ) { return ( malloc ( sizeof ( struct node ) ) ) ; } int next ( int mask [ ] , int n ) { int i ; for ( i = 0 ; ( i < n ) && mask [ i ] ; ++ i ) mask [ i ] = 0 ; if ( i < n ) { mask [ i ] = 1 ; return 1 ; } return 0 ; } int main ( void ) { int rows ; int i , j , k , count ; int r , c ; int bin [ 100 ] ; int sum = 0 ; int testcases ; NODE temp , head , cur ; scanf ( "%d" , & testcases ) ; for ( count = 0 ; count < testcases ; count ++ ) { temp = getnode ( ) ; scanf ( "%d" , & rows ) ; if ( rows <= 0 || rows > 100 ) exit ( 1 ) ; for ( i = 1 ; i <= rows ; i ++ ) for ( j = 0 ; j < i ; j ++ ) { scanf ( "%d" , & temp -> triangle [ i - 1 ] [ j ] ) ; if ( temp -> triangle [ i - 1 ] [ j ] <= 0 || temp -> triangle [ i - 1 ] [ j ] > 99 ) exit ( 1 ) ; } if ( count == 0 ) { head = temp ; cur = head ; } else { cur -> next = temp ; cur = cur -> next ; } } cur = head ; for ( count = 0 ; count < testcases ; count ++ ) { cur -> max = 0 ; for ( j = 0 ; j < rows ; j ++ ) { bin [ j ] = 0 ; cur -> max += cur -> triangle [ j ] [ 0 ] ; } while ( next ( bin , rows - 1 ) ) { k = 0 ; r = 0 ; c = 0 ; sum = 0 ; for ( j = 0 ; j < rows ; j ++ ) { sum += cur -> triangle [ r ++ ] [ c ] ; c = c + bin [ k ++ ] ; } if ( sum > cur -> max ) cur -> max = sum ; } cur = cur -> next ; } printf ( "\n" ) ; cur = head ; while ( cur != NULL ) { printf ( "%d\n" , cur -> max ) ; cur = cur -> next ; } return 0 ; }
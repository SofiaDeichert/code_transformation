int done [ 1005 ] , chef [ 1005 ] ; int main ( ) { int n = 0 , m = 0 , l , i , j , d , b = 0 , flag = 0 ; scanf ( "%d" , & l ) ; for ( i = 0 ; i < l ; i ++ ) { b = 0 ; scanf ( "%d %d" , & n , & m ) ; for ( j = 0 ; j < n ; j ++ ) { done [ j ] = 0 ; chef [ j ] = 0 ; } for ( j = 0 ; j < m ; j ++ ) { scanf ( "%d" , & done [ j ] ) ; } for ( j = 1 ; j <= n ; j ++ ) { flag = 0 ; for ( d = 0 ; d < m ; d ++ ) { if ( j == done [ d ] ) flag = 1 ; } if ( flag == 0 ) { chef [ b ] = j ; b ++ ; } } for ( j = 0 ; j < ( n - m ) ; j += 2 ) { printf ( "%d " , chef [ j ] ) ; } printf ( "\n" ) ; for ( j = 1 ; j < ( n - m ) ; j += 2 ) { printf ( "%d " , chef [ j ] ) ; } printf ( "\n" ) ; } return 0 ; }
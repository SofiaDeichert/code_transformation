int a [ ROWS ] ; int lowerBound ; int upperBound ; char buffer [ N ] ; int max ( index , n ) { if ( index >= lowerBound && index <= upperBound ) { return a [ index ] ; } else { int offset = index - ( n - 1 ) * n / 2 ; int downIndex = n * ( n + 1 ) / 2 + offset ; int rightIndex = downIndex + 1 ; int downMaxSum = max ( downIndex , n + 1 ) ; int rightMaxSum = max ( rightIndex , n + 1 ) ; return a [ index ] + ( downMaxSum > rightMaxSum ? downMaxSum : rightMaxSum ) ; } } int main ( ) { int t ; scanf ( "%d" , & t ) ; int lines ; int j ; int c ; int inputN = 1 ; int n = 0 ; long innerC = 0 ; long x = - 1 ; long q ; int temp = 0 ; do { c = read ( 0 , buffer , N ) ; for ( j = 0 ; j < c ; j ++ ) { if ( buffer [ j ] == '\n' && inputN ) { q = temp * ( temp + 1 ) / 2 ; n = temp ; temp = 0 ; inputN = 0 ; } else if ( ( buffer [ j ] == '\n' || buffer [ j ] == ' ' ) && ! inputN ) { x ++ ; a [ x ] = temp ; temp = 0 ; if ( ( x + 1 ) == q ) { innerC ++ ; inputN = 1 ; lowerBound = ( n - 1 ) * n / 2 ; upperBound = ( n + 1 ) * n / 2 - 1 ; printf ( "%d\n" , max ( 0 , 1 ) ) ; x = - 1 ; if ( innerC == t ) break ; } } else { temp = temp * 10 + buffer [ j ] - '0' ; } } } while ( innerC != t ) ; return 0 ; }
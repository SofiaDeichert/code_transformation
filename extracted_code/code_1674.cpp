unsigned int numRows = 0 ; void ReadInput ( char * data , int num ) { int i = 0 ; for ( i = 0 ; i < num ; i ++ ) { scanf ( "%d" , & data [ i ] ) ; fflush ( stdin ) ; } } void AnalyseData ( ) { int * sum = NULL ; char * data = NULL ; int i = 0 , j = 0 ; int max = 0 ; scanf ( "%d" , & numRows ) ; fflush ( stdin ) ; sum = ( int * ) malloc ( numRows * sizeof ( int ) ) ; for ( i = 0 ; i < numRows ; i ++ ) { data = ( char * ) malloc ( ( 1 + i ) * sizeof ( char ) ) ; ReadInput ( data , i + 1 ) ; for ( j = 0 ; j < i ; j ++ ) { if ( data [ j ] > data [ j + 1 ] ) sum [ j ] += data [ j ] ; else sum [ j ] += data [ j + 1 ] ; } sum [ i ] = data [ i ] ; free ( data ) ; } for ( i = 0 ; i < numRows ; i ++ ) { if ( max < sum [ i ] ) max = sum [ i ] ; } free ( sum ) ; printf ( "%d\n" , max ) ; } int main ( ) { unsigned int numTestCases = 0 ; int i = 0 ; scanf ( "%d" , & numTestCases ) ; fflush ( stdin ) ; for ( i = 0 ; i < numTestCases ; i ++ ) { AnalyseData ( ) ; numRows = 0 ; } return 0 ; }
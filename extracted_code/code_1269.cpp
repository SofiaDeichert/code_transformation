void calculate ( ) ; int mylog ( int num ) ; int main ( int argc , char * argv [ ] ) { int triangleCount ; scanf ( "%d" , & triangleCount ) ; while ( triangleCount > 0 ) { calculate ( ) ; triangleCount -- ; } return EXIT_SUCCESS ; } void calculate ( ) { int lineCount , lineNum , sumLen , i , max ; scanf ( "%d" , & lineCount ) ; int line [ lineCount ] ; int sum [ 1000000000 ] ; lineCount = 0 ; lineNum = 0 ; sumLen = 0 ; max = 0 ; while ( lineCount > 0 ) { int i ; lineNum ++ ; for ( i = 0 ; i < lineNum ; i ++ ) scanf ( "%d" , & line [ i ] ) ; if ( lineNum == 1 ) { sum [ 0 ] = line [ 0 ] ; sumLen = 1 ; } else { for ( i = sumLen ; i > 0 ; i -- ) { int lineC = mylog ( i ) ; sum [ ( 2 * i ) - 1 ] = sum [ i - 1 ] + line [ lineC + 1 ] ; sum [ ( 2 * i ) - 2 ] = sum [ i - 1 ] + line [ lineC ] ; } sumLen *= 2 ; } lineCount -- ; } for ( i = 0 ; i < sumLen ; i ++ ) { if ( sum [ i ] > max ) max = sum [ i ] ; } printf ( "%d\n" , max ) ; } int mylog ( int num ) { int count = 0 ; while ( num > 0 ) { num = num / 2 ; count ++ ; } return count - 1 ; }
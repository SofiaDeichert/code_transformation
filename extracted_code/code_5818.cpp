int main ( ) { int i , j , max , val , idx , N , NN , sum , tempidx ; scanf ( "%d" , & N ) ; while ( N -- ) { scanf ( "%d" , & NN ) ; sum = 0 ; scanf ( "%d" , & val ) ; sum += val ; idx = 0 ; for ( i = 1 ; i < NN ; i ++ ) { max = 0 ; for ( j = 0 ; j < i ; j ++ ) { scanf ( "%d" , & val ) ; if ( val > max && ( ( j == idx ) || ( j == idx + 1 ) ) ) { max = val ; tempidx = j ; } } idx = tempidx ; sum += max ; } printf ( "%d\n" , sum ) ; } return 0 ; }
int main ( ) { unsigned short int tests ; int a , b , max , min , mod ; scanf ( "%hu" , & tests ) ; while ( tests -- ) { scanf ( "%d %d" , & a , & b ) ; max = ( a > b ? a : b ) ; min = ( a < b ? a : b ) ; mod = max % min ; while ( mod ) { max = min ; min = mod ; mod = max % min ; } printf ( "%d %d\n" , min , ( ( a * b ) / min ) ) ; } return 0 ; }
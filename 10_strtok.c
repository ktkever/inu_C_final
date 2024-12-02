#include <string.h>
#include <stdio.h>

char s[] = "Man is immortal, because he has a soul";
char seps[]   = " ,\t\n";    //seperator
char *token;     //분리된 단어의 주소

int main( void )
{
	// 문자열을 전달하고 다음 토큰을 얻는다. 
	token = strtok( s, seps ); 
	while( token != NULL )
	{
		// 문자열 s에 토큰이 있는 동안 반복한다. 
	      printf( "토큰: %s\n", token );
		// 다음 토큰을 얻는다. 
	      token = strtok( NULL, seps ); // 자른 후 문자열에서 새로 자르기 시작
   	}	
	printf("%s",token);
	return 0;
}

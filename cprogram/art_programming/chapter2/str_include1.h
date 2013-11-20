#ifndef STR_INCLUDE1_H
#define STR_INCLUDE1_H
int str_include1(char* strlong, char* strshort)
{
	if(strlong == NULL || strshort == NULL)
		return -1;
	char* p_short, *p_long;
	for(p_short = strshort; *p_short != '\0'; ++p_short)
	{
		for(p_long = strlong; *p_long != '\0'; ++p_long)
		{
			if(*p_short == *p_long)
				break;
		}
		if(*p_long == '\0')
			return 0;
		if(*(p_short+1) == '\0')
			return 1;
	}
}
#endif

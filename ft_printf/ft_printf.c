

#include "libft.h"
#include "ft_printf.h"

static	int	has_format_tag(char *string)	//문자열에 %가 있으면 1을 출력 없으면 0을 출력
{
	if (ft_strchr(string, '%'))
		return (1);
	return (0);
}

int	send_output(char *string)
{
	return (write(1, string, ft_strlen(string)));
}

int	ft_printf(const char *string, ...)
{
	va_list	ap;		//가변인자 목록 포인터 
	int		count;
	int		tmp_count;
	char	*tmp_string;

	if (!has_format_tag((char *)string))		//문자열에 %가 없다고 하면 string그대로 출력
		return (send_output((char *)string));
	va_start(ap, string);						//string다음의 인자들 부터 리스트에 넣는다.
	tmp_string = (char *)string;				//const풀고
	count = write_ap(&tmp_string, ap);		// 맨 처음 가변인자값 있으면 출력하고 count에 0대입, string에 %없으면 string그대로 쓰고 0이 아닌 값 대입 
	tmp_count = 1;
	while (*tmp_string && tmp_count != -1)	//tmp_count가 -1인 경우는 find_prefix의 substr이 오류났을 때 //tmp_string이 널일때는 문자열을 다 출력했을 때 .
	{
		tmp_count = write_ap(&tmp_string, ap);
		count += tmp_count;			//출력한 문자열의 길이를 계속 업데이트
	}
	va_end(ap);
	if (tmp_count == -1)	//find_prefix의 substr이 오륲나면 함수 종료
		return (tmp_count);
	return (count);
}

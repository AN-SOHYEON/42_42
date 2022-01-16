

#include "ft_printf.h"
#include "libft.h"

static int	find_prefix(char **string)	//*는 각 문자의 주소값을, **은 찐문자열의 한문자 그대로(값)를 나타냄 //0을 출력해야 형식을 찾는 기능을 수행하게 함. 
{
	char	*tmp_string;
	char	*start;
	int		count;
	// 함수들이 인자로 일차원 포인터를 받으므로 *string을 전달한다. 
	start = ft_strchr(*string, '%');	//%가 있으면 있는 곳의 주소값을, 없으면 널을 반환
	if (!start)		//널이면 %가 없으므로
	{
		count = send_output(*string);	//string을 그대로 출력하고 count에는 문자열 길이가 담긴다. 
		*string = ft_strchr(*string, '\0');	//다 출력하고 나면 문자열의 널이 있는 곳, 가장 끝으로 주소값을 옮긴다. 
		return (count);
	}
	if (!(start - *string))		//일단 %가 있는 문자열이고 조건문이 널이려면 이 문자열의 가장 처음문자가 % 이라는 뜻 그럼 바로 이 함수 끝냄 
		return (0);
	tmp_string = ft_substr(*string, 0, start - *string);	//string의 처음부터 %가 나올 때까지의 문자열을 반환
	if (!tmp_string)	//substr 에러 처리
		return (-1);
	count = send_output(tmp_string);	//일단 %앞부분까지를 출력
	*string = start; //앞부분을 출력 해놨으니 string의 첫 위치를 %으로 옮김. 
	free(tmp_string);
	return (count);
}

static char	find_format(char **string)		//서식지정자 알파멧 찾아서 반환 
{
	char	format;

	format = (*string)[1];
	*string = *string + 2;
	return (format);
}

static int	format_invalid(char format)	//잘못된 포맷은 그냥 그대로 출력하겠다. 
{
	ft_putchar_fd('%', 1);
	ft_putchar_fd(format, 1);
	return (2);
}

static int	find_format_writer(char format, va_list ap)
{
	if (format == 'c')
		return (write_char(ap));
	if (format == 's')
		return (write_str(ap));
	if (format == 'p')
		return (write_ptr(ap));
	if (format == 'd' || format == 'i')
		return (write_int(ap));
	if (format == 'u')
		return (write_uint(ap));
	if (format == 'x' || format == 'X')
		return (write_hex(format, ap));
	if (format == '%')
		return (write_percent());
	else
		return (format_invalid(format));
}

int	write_ap(char **string, va_list ap)	//count가 0이면 가변인자에 해당하는 값을 출력하고 0반환, 0이 아니면 그냥 바로 그 int값 반환 
{
	int		count;

	if (**string)	//문자열 이 끝이 아니면 
	{
		count = find_prefix(string);
		if (count)	//0이 아니면 
			return (count);	// 그대로 출력
		return (find_format_writer(find_format(string), ap));	//0이면 형식 찾아서 write함수 실행 //만일 잘못된 형식있을 때 2를 리턴하는데 이건 문자 2개를 썼으니까 2를 리턴하는거다 그 다음 문자열부터 다시 로직 수행 
	}
	return (0);
}
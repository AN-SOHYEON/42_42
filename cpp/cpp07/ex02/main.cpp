/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: san <san@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 15:02:09 by san               #+#    #+#             */
/*   Updated: 2022/08/05 15:02:11 by san              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
# include <cstdlib>
# include <ctime>

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
        //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
        try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
        try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    std::cout << "==================deepcopy=====================" << std::endl;
    for (int i = 0; i < 20; i++)
    {
        std::cout << numbers[i] << " || " << mirror[i] << std::endl;
    }
    delete [] mirror;//

    std::cout << "==================san test for deep copy=====================" << std::endl;

    Array<char> ch(10);
    for (int i = 0; i < 10; i++)
    {
        int   value;
        while (1)
        {
            value = rand() % 130;
            if (value > 33 && value < 126)
                break;
        }
        ch[i] = value;
    }
    Array<char> tt(ch);
    Array<char> oo = ch;

    std::cout << "==========after copy=========" << std::endl;

    for (int i = 0; i < 5; i++)
    {
        std::cout << ch[i] << " || " << tt[i] << " || " << oo[i] << std::endl;
    }
    for (int i = 0; i < 5; i++)
    {
        int   value;
        while (1)
        {
            value = rand() % 130;
            if (value > 33 && value < 120)
                break;
        }
        tt[i] = value;
        oo[i] = value + 2;
    }

    std::cout << "==========after change=========" << std::endl;
    for (int i = 0; i < 5; i++)
    {
        std::cout << ch[i] << " || " << tt[i] << " || " << oo[i] << std::endl;
    }

    std::cout << "==========out of bound=========" << std::endl;
    try
    {
        std::cout << ch[11] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    

    system("leaks tem02");
    return 0;
}

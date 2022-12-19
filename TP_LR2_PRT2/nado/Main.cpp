
#include <iostream>


#include <string>
#include <vector>
#include <sstream>
#include <fstream>

#include "Marray.h"


using namespace std;



/*
С использованием файловых и строковых потоков написать программу,
которая считывает текст из файла и выводит на экран только предложения,
состоящие из заданного количества слов.

*/






int main()
{
    setlocale(LC_ALL, "Russian");
    
    std::ifstream ifs("in.txt");


    List<std::string> vec;
    //std::vector<std::string> vec;
    size_t n = 0;
    std::cout << "Input count words in sentence: ";
    std::cin >> n;

    if (!ifs)
    {
        std::cerr << "ERROR" << std::endl;
        return 1;
    }

    else
    {
        while (!ifs.eof())
        {
            std::string tmp;

            getline(ifs, tmp, '.');
            vec.push_back(tmp);
        }
    }

    size_t cnt;
    for (size_t i = 0; i < vec.size(); ++i)
    {
        cnt = 0;
        std::string tmp = vec[i];
        std::istringstream ist(tmp);

        while (ist >> tmp)
            ++cnt;  

        if (cnt == n)
        { 
            std::cout << vec[i] << '.';
            std::cout << '\n';
        }
    }

    return 0;
}
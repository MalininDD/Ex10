// Copyright 2021 MalininDmitry
#include <iostream>
#include <string>
#include "../include/postfix.h"

int main() {
    std::string s1("9 + 5 * (3.14 - 6.17) * 7");
    std::cout << s1 << std::endl;
    std::string s_out = infix2postfix(s1);
    std::cout << s_out << std::endl;
    std::string s2("7 + 4");
    std::cout << s2 << std::endl;
    std::string s_out2 = infix2postfix(s2);
    std::cout << s_out2 << std::endl;
    std::string s3("(2 + 4) * (4.5557 - 4.53434)");
    std::cout << s3 << std::endl;
    std::string s_out3 = infix2postfix(s3);
    std::cout << s_out3 << std::endl;

    return 0;
}

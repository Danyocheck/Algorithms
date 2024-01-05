#include <iostream>
#include <stack>

int
main()
{
    std::string str;
    std::stack<char> stack;
    std::cin >> str;
    for (int i = 0; i < str.size(); ++i) {
        if (stack.empty()) {
            stack.push(str[i]);
            continue;
        }
        switch (stack.top()) {
            case '(':
                if (str[i] == ')') {
                    stack.pop();
                } else {
                    stack.push(str[i]);
                }
                break;
            case '[':
                if (str[i] == ']') {
                    stack.pop();
                } else {
                    stack.push(str[i]);
                }
                break;
            case '{':
                if (str[i] == '}') {
                    stack.pop();
                } else {
                    stack.push(str[i]);
                }
                break;
            default: break;
        }
    }

    if (stack.empty()) {
        std::cout << "yes" << std::endl;
    } else {
        std::cout << "no" << std::endl;
    }

    return 0;
}
#include <iostream>



int main (int argc, char* argv[]) {
    double operand1,operand2;
    double total;
    int op = 0;  // +: 1 -:2 /:3 *:4 %: 5
    char operation;
    std::cin >> operand1;
    total = operand1;
    while (true) {
        std::cin >> operation;
        switch(operation) {
            case '+':
                op = 1;
                break;
            case '-':
                op = 2;
                break;
            case '/':
                op = 3;
                break;
            case '*':
                op = 4;
                break;
            case '%':
                op = 5;
                break;
            case 'c':
                total = 0;
                std::cout << total << std::endl;
                continue;
            case 'e':
                return 0;
            default:
                std::cerr << "Unsupported operator\n";
                return 1;
        }
        std::cin >> operand2;
        if (op == 1) total += operand2;
        if (op == 2) total -= operand2;
        if (op == 3) total /= operand2;
        if (op == 4) total *= operand2;
        if (op == 5) total = (int)total % (int)operand2;
        std::cout <<"_______\n";
        std::cout << total << std::endl;
    }
    return 0;
}

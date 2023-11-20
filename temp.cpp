#include <iostream>
#include <cstdio>
#include <cstring>

double ctof(double);
double ctok(double);
double ktoc(double);
double ftoc(double);
int invalid();

int main(int argc, char* argv[]) {
    double value = 0.0;
    int selection1, selection2;
    bool fromK = 0, fromC = 0, fromF = 0, quiet = 0, scli = 0,tcli = 0;
    if (argc > 1) {
        if (!strcmp(argv[1],"-h")) {
            std::cout << "Usage: " << argv[0] << "[OPTIONS]\n\t-s\tsource unit 1:Celsius, 2:Fahrenheit, 3:Kelvin\n\t-t\ttarget unit 1:Celsius, 2:Fahrenheit, 3:Kelvin\n\t-q quiet suppress output";
            return 1;
        }
        for (int i = 1; i < argc - 1; i++) {
            if(!strcmp(argv[i],"-s")) {
                selection1 = std::stod(argv[i+1]);
                scli = 1;
                i++;
                continue;
            } 
            if (!strcmp(argv[i],"-t")) {
                selection2 = std::stod(argv[i+1]);
                tcli = 1;
                i++;
                continue;
            }
            if (!strcmp(argv[i],"-q")){
                quiet = 1;
            }
        }
        value = std::stod(argv[argc-1]);

    }

    if (!quiet) std::cout << "Welcome to conversion tool\n1.Celsius\t2.Fahrenheit\t3.Kelvin\n";
    if (!scli) std::cin >> selection1;
    switch(selection1) {
        case 1:
            fromC = 1;
            break;
        case 2:
            fromF = 1;
            break;
        case 3:
            fromK = 1;
            break;
        default:
            return invalid();
    }
    if(!quiet) std::cout << "temperature: ";
    if(value == 0.0) std::cin >> value;
    if(!quiet) std::cout << "target unit:\n1.Celsius\t2.Fahrenheit\t3.Kelvin\n";
    if (!tcli) std::cin >> selection2;
    switch(selection2) {
        case 1:
            if(fromC) {std::cout << value << std::endl; return 0;}
            if(fromF) {std::cout << ftoc(value) << std::endl; return 0;}
            if(fromK) {std::cout << ktoc(value) << std::endl; return 0;}
        case 2:
            if(fromC) {std::cout << ctof(value) << std::endl; return 0;}
            if(fromF) {std::cout << value << std::endl; return 0;}
            if(fromK) {std::cout << ctof(ktoc(value)) << std::endl; return 0;}
        case 3:
            if(fromC) {std::cout << ctok(value) << std::endl; return 0;}
            if(fromF) {std::cout << ctok(ftoc(value)) << std::endl; return 0;}
            if(fromK) {std::cout << value << std::endl; return 0;}
        default:
            return invalid();
    }
}

int invalid() {
    std::cerr << "Invalid option\n";
    return 1;
}

double ctof(double celsius){ 
   // F = (C * 1.8) + 32
   return (celsius * 1.8) + 32;
}

double ctok(double celsius) {
    // C = K - 273.15
    return celsius + 273.15;
}

double ktoc(double kelvin) {
    return kelvin - 273.15;
}

double ftoc(double fahr) {
    return (fahr - 32)/1.8;
}

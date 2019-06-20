//
//  main.cpp
//  new_ID_calculator
//
//  Created by Sandu on 6/10/19.
//  Copyright © 2019 Sandu. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    int x;
    std::cout << "Enter last three digits of your ID number \n";
    std::cin >> x;
    x += 1000;
    char y;
    std::cout <<  "Enter the first letter of your first name (capital letter)\n";
    std::cin >> y;
    char z;
    std::cout <<  "Enter the first letter of your second name (capital letter)\n";
    std::cin >> z;
    
    unsigned int new_ID = x*x - 13*x + int(y) + int(z);
    
    std::cout << "Your new ID is\t" << new_ID <<"\n";
    return 0;
}

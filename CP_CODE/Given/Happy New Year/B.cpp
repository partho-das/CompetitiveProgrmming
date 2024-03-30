#include <iostream>

int main()
{
    unsigned int n, i;
    std::cin >> n;
    std::string line[n];
    for(i = 0; i < n; i++) std::getline(std::cin, line[n]);
    for(i = 0; i < n; i++) std::cout << line[n] << std::endl;
    return 0;
}

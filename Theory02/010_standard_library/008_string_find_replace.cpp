#include <iostream>
#include <string>

int main()
{
    std::string text = "C++ is one of the hardest language.";

    std::string target = "hardest";
    std::string replacement = "most powerful";

    std::size_t pos = text.find(target);
    if (pos != std::string::npos)
    {
        text.replace(pos, target.length(), replacement);
        std::cout << "Replaced text = " << text << std::endl;
    }
    else
    {
        std::cout << "Do not find target [" << target << "] string in text." << std::endl;
    }

    return 0;
}
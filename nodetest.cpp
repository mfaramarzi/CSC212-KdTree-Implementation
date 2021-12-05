#include "node.h"

int main()
{
    std::vector<int> test{2,3};
    Node node(test);
    std::cout << test[0] << " " << test[1] << "\n";

    node.getData();

    return 0;
}
#include <vector>
#include <memory>

struct bag;

void knapsack_test();

void knapsack(const int& weight, const std::vector<std::unique_ptr<bag>>& bags);

void knapsack_unique_bag(const int& weight, const std::vector<std::unique_ptr<bag>>& bags);


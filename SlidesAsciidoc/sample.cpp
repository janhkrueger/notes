#include<iostream>

double getCurrentValue(int total_levels, double start_value, double end_value, int current_level) {
    double difference = end_value - start_value;
    double increments = difference / (total_levels - 1);

    double current_value;

    if(current_level == 1) {
        current_value = start_value;
    } else if(current_level == total_levels) {
        current_value = end_value;
    } else {
        current_value = start_value + (increments * (current_level - 1));
    }

    return current_value;
}

int main() {
    double start_value = 5;
    double end_value = 30;
    int total_levels = 10;
    int current_level = 5; // You can set the current_level value as needed

    double value = getCurrentValue(total_levels, start_value, end_value, current_level);
    std::cout << "Value at level " << current_level << " is: " << value << "\n";

    return 0;
}

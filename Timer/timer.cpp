#include <iostream>
#include <chrono>
#include <thread>
#include <iomanip> // For std::setw and std::setfill

void countDownTimer(int minute) {
    std::chrono::minutes duration(minute); // Set duration to 1 minute
    const auto start = std::chrono::steady_clock::now();
    std::chrono::duration<double> time_left = duration - (std::chrono::steady_clock::now() - start);

    while (time_left > std::chrono::seconds(0)) {
        // Calculate remaining time components
        const auto mins = std::chrono::duration_cast<std::chrono::minutes>(time_left);
        const auto secs = std::chrono::duration_cast<std::chrono::seconds>(time_left - mins);

        // Print remaining time (formatted)
        std::cout << "\rTime left: " << std::setfill('0') << std::setw(2) << mins.count() << ":"
                  << std::setfill('0') << std::setw(2) << secs.count() << std::flush;

        // Sleep briefly to avoid high CPU usage
        std::this_thread::sleep_for(std::chrono::seconds(1));

        // Recalculate time left for the next iteration
        time_left = duration - (std::chrono::steady_clock::now() - start);
    }

    std::cout << "\nTimer done!" << std::endl;
    return;
}
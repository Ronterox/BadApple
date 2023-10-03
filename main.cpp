#include <iostream>
#include <filesystem>
#include <fstream>
#include <thread>
#include <chrono>
#include <vector>
#include <algorithm>

#define LOG(x) std::cout << x << std::endl

namespace fs = std::filesystem;

void clean() {
    // CSI[2J clears screen, CSI[H moves the cursor to top-left corner
    std::cout << "\x1B[2J\x1B[H" << std::endl; // ANSI ESCAPE CODE
}

int main() {
    const char folderpath[] = "frames-ascii";
    system("mpv badapple.mp4 &");

    std::vector<fs::path> files;
    std::copy(fs::directory_iterator(folderpath), fs::directory_iterator(), std::back_inserter(files));
    std::sort(files.begin(), files.end());

    for (const std::string& filename : files) {
	std::ifstream frame(filename);
	while (frame) std::cout << (char)frame.get();

	std::this_thread::sleep_for(std::chrono::milliseconds(33)); // 33 ms
	clean();
    }
    return 0;
}


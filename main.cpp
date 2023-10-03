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
    // TODO: this path also parameter
    const char folderpath[] = "frames-ascii";

    // TODO: Download file, still thinking if py or full c++
    system("mpv --loop=no badapple.mp4 &");

    std::vector<fs::path> files;
    std::copy(fs::directory_iterator(folderpath), fs::directory_iterator(), std::back_inserter(files));
    std::sort(files.begin(), files.end());

    // TODO: files ascii generation, still thinking if py or full c++
    for (const std::string& filename : files) {
	std::ifstream frame(filename);
	while (frame) std::cout << (char)frame.get();

	// TODO: Parameter ms for other machines
	std::this_thread::sleep_for(std::chrono::milliseconds(33));
	clean();
    }
    return 0;
}


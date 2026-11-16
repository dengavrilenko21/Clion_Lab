#include <iostream>
#include <string>
using namespace std;
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

int main() {
    string input_path = "../Lab5/KNU.png";
    string output_path = "../Lab5/rotated.png";

    int width, height, channels;
    auto img = stbi_load(input_path.c_str(), &width, &height, &channels, 0);
    if (!img) {
        cout << "file not found" << endl;
        return 1;
    }

    long long sum_r = 0, sum_g = 0, sum_b = 0;
    int total_pixels = width * height;

    for (int i = 0; i < total_pixels; i++) {
        sum_r += img[i * channels];
        sum_g += img[i * channels + 1];
        sum_b += img[i * channels + 2];
    }

    cout << "Average RGB: "
         << sum_r / total_pixels << " "
         << sum_g / total_pixels << " "
         << sum_b / total_pixels << endl;

    auto rotated = new unsigned char[total_pixels * channels];
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int old_pos = (y * width + x) * channels;
            int new_pos = (x * height + (height - 1 - y)) * channels;

            for (int c = 0; c < channels; c++) {
                rotated[new_pos + c] = img[old_pos + c];
            }
        }
    }

    stbi_write_png(output_path.c_str(), height, width, channels, rotated, height * channels);

    stbi_image_free(img);
    delete[] rotated;

    return 0;
}
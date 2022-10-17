#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <fstream>
#include <string>

#pragma
using namespace std::chrono;

void write_to_csv(std::string &fileName, int arrayLength, long long int duration);

void print(int *, int);

int *getArray(int);

void insertionSort(int *, int);

// Change it to the main to run as batch mode
int main2() {

    std::string file_name = "./out.csv";

    //std::ofstream file;
    //file.open(file_name, std::ios::out);
    // Set the seed for random numbers
    std::srand(time(nullptr));

    // set size for the array
    int size;

    for (size = 100; size < 1000000; size = size + 50000) {
        // generate random arrays with size
        int *list = getArray(size);
        /*
        int *list = new int[size];
        for (int i = 0; i < size; ++i) {
            list[i] = rand() % size;
        }*/
        //print(list, size);

        std::cout << "List Size: " << size << std::endl;

        // print the array
        //print(list, size);

        auto start = high_resolution_clock::now();
        insertionSort(list, size);
        auto end = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(end - start);

        std::cout << "Duration: " << duration.count() << std::endl;

        //if (file.is_open()) {
        //    file << size << "," << duration.count() << std::endl;
        //}
        write_to_csv(file_name, size, duration.count());
        /*
        try {
            write_to_csv(file_name, size, duration.count());
        }
        catch (std::exception &e) {
            std::cout << "CANNOT WRITE TO FILE " << size << std::endl;
        }
        */

    }
    int *list = NULL;
    delete list;

    //file.close();
    return 0;
}


void write_to_csv(std::string &fileName, int arrayLength, long long int duration) {
    std::string l = std::to_string(arrayLength);
    std::string d = std::to_string(duration);

    std::ofstream file;
    file.open(fileName, std::ios::app);
    if (file.is_open()) {
        file << l << "," << d << std::endl;
        file.close();
    }
    //if (file.is_open()) {

}

void print(int *array, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

int *getArray(int size) {
    int *arr = new int[size];
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % size;

    }
    return arr;
}

void insertionSort(int *array, int size) {
    int key, j;
    for (int i = 1; i < size; ++i) {
        float remaining = (float(i) / float(size)) * 100;
        std::cout << "Current Index: " << i << " Progress: %" << remaining << "\r" << std::flush;
        key = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
    //print(array, size);
    std::cout << std::endl;
}






#include <cstdlib>
#include <iostream>
#include <string>

#include <cuda_runtime.h>

#include <optix.h>
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#include <optix_stubs.h>
#pragma GCC diagnostic pop
#include <optix_function_table_definition.h>

using namespace std;

void check(cudaError_t result) {
        if (result != cudaSuccess) {
                cerr << "Cuda error: " << result << endl;
                exit(EXIT_FAILURE);
        }
}

void check(OptixResult result) {
        if (result != OPTIX_SUCCESS) {
                cerr << "Optix error: " << result << endl;
                exit(EXIT_FAILURE);
        }
}

int main() {
        int count = 0;
        check(cudaGetDeviceCount(&count));
        cout << "Found " << count << " CUDA device" << (count > 1 ? "s" : " " ) << endl;
        check(optixInit());
        return EXIT_SUCCESS;
}

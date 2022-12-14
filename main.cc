#include <cstdlib>
#include <iostream>
#include <string>
#include <string_view>

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

void check(CUresult result) {
        if (result != CUDA_SUCCESS) {
                cerr << "Cuda error: " << result << endl;
                exit(EXIT_FAILURE);
        }
}

void error(string_view message) {
        cerr << "Error: " << message << endl;
        exit(EXIT_FAILURE);
}

void info(string_view message) {
        cout << message << endl;
}

void log(
        unsigned int level,
        const char *tag,
        const char *message,
        void *data) {

        (void)data;
        cerr << level << " " << tag << " " << message << endl;
}

int main() {
        int numberDevices = 0;
        check(cudaGetDeviceCount(&numberDevices));
        if (numberDevices == 0) {
                error("Didn't find a graphics device!");
        }
        check(optixInit());

        const int device = 0;
        check(cudaSetDevice(device));

        CUstream stream;
        check(cudaStreamCreate(&stream));

        cudaDeviceProp properties;
        check(cudaGetDeviceProperties(&properties, device));
        info(string("Device: ") + properties.name);

        CUcontext cudaContext;
        check(cuDevicePrimaryCtxRetain(&cudaContext, device));

        OptixDeviceContext optixContext;
        check(optixDeviceContextCreate(cudaContext, nullptr, &optixContext));

        unsigned int level = 4;
        check(optixDeviceContextSetLogCallback(optixContext, log, nullptr, level));

        return EXIT_SUCCESS;
}

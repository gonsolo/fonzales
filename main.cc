#include <cstdlib>
#include <iostream>
#include <string>

#include <optix.h>
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#include <optix_stubs.h>
#pragma GCC diagnostic pop
#include <optix_function_table_definition.h>

using namespace std;

void check(OptixResult result) {
        if (result != OPTIX_SUCCESS) {
                cerr << "Error: " << result << endl;
                exit(EXIT_FAILURE);
        }
}

int main() {
        check(optixInit());
        return EXIT_SUCCESS;
}

#include "fomalib.h"
#include <string>
#include <iostream>

using namespace std;
char model_path_cstr[255];

int main() {
    string model_path("/home/t-linan/projects/foma/foma/localdata/temp.foma");
    string input("avoid writing ad hoc code ad hoc");
    char* model_path_cstr = strdup(model_path.c_str());
    fsm* net = fsm_read_binary_file(model_path_cstr);
    free(model_path_cstr);
    if (net == NULL) {
        cout<< "file_fomat error" << endl;
	    exit(0);
    }
    apply_handle* handle = apply_init(net);
    char* input_cstr = strdup(input.c_str());
    char* result_cstr = apply_down(handle, input_cstr);
    free(input_cstr);
    if(result_cstr != NULL) {
        string result(result_cstr);
        cout << "result:" << result << endl;
    }

    if (handle != NULL) {
	    apply_clear(handle);
	}
	if (net != NULL) {
	    fsm_destroy(net);
	}
}
#include "fomalib.h"
#include <string>
#include <iostream>

using namespace std;
char model_path_cstr[255];

int main() {
    string model_path("/home/t-linan/projects/foma/foma/localdata/temp.foma");
    string input("avoid writing ad hoc code ad hoc");
    fsm* net = fsm_read_binary_file(strdup(model_path.c_str()));
    if (net == NULL) {
        cout<< "file_fomat error" << endl;
	    exit(0);
    }
    apply_handle* handle = apply_init(net);
    char* result_cstr = apply_down(handle, strdup(input.c_str()));
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
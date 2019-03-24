#include "optgen.h"

void OPTgen::init(uint64_t size){
    num_cache = 0;
    access = 0;
    cache_size = size;
    liveness_intervals.resize(OPTGEN_SIZE, 0);
}

//Return number of hits
uint64_t OPTgen::get_optgen_hits(){
    return num_cache;
}

void OPTgen::set_access(uint64_t val){
    access++;
    liveness_intervals[val] = 0;
}

void OPTgen::set_prefetch(uint64_t val){
    liveness_intervals[val] = 0;
}

//Return if hit or miss
bool OPTgen::is_cache(uint64_t val, uint64_t endVal){
    bool cache = true;
    unsigned int count = endVal;
    while (count != val){
        if(liveness_intervals[count] >= cache_size){
            cache = false;
            break;
        }
        count = (count+1) % liveness_intervals.size();
    }

    if(cache){
        count = endVal;
        while(count != val){
            liveness_intervals[count]++;
            count = (count+1) % liveness_intervals.size();
        }
        num_cache++;
    }
    return cache;
}
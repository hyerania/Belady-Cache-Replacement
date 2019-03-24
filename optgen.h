#ifndef OPTGEN_H
#define OPTGEN_H

using namespace std;

#include <vector>
#define OPTGEN_SIZE 128

struct OPTgen{
    vector<unsigned int> liveness_intervals;
    uint64_t num_cache;
    uint64_t access;
    uint64_t cache_size;

    
    void init(uint64_t size);       //Initialize values
    uint64_t get_optgen_hits();     //Return number of hits
    void set_access(uint64_t val);
    void set_prefetch(uint64_t val);
    bool is_cache(uint64_t val, uint64_t endVal);   //Return if hit or miss
};

#endif
#ifndef OPTGEN_H
#define OPTGEN_H

using namespace std;

#include <vector>
#define OPTGEN_SIZE 128

struct optgen{
    vector<int> liveness_intervals;
    int num_cache;
    int access;
    int cache_size;

    void init(int size){
        num_cache = 0;
        access = 0;
        cache_size = size;
        liveness_intervals.resize(OPTGEN_SIZE, 0);
    }

    int get_optgen_hits(){
        return num_cache;
    }

    void set_access(int val){
        access++;
        liveness_intervals[val] = 0;
    }

    void set_fetch(int val){
        liveness_intervals[val] = 0;
    }

    bool is_Cache(int val, int endVal){
        bool cache = true;
        int count = endVal;
        while (count != val){
            if(liveness_intervals[count] >= cache_size){
                cache = false;
                break;
            }
            count = (count+1) % liveness_intervals.size();
        }

        if(cache){
            int count = endVal;
            while(count != val){
                liveness_intervals[count]++;
                count = (count+1) % liveness_intervals.size();
            }
            num_cache++;
        }
        return cache;
    }
}

#endif